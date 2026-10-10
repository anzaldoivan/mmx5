// ExportBoundaries.java -- postScript for tools/ghidra/import.sh (after ImportOverlays): writes arg 1
// (docs/oracle/boundaries.txt), one line per boundary `<start>-<end> | <kind> | <owner> | <evidence>`,
// end exclusive, 8 hex uppercase, overlay starts prefixed `ovlNN:`; exe first by addr, then overlay
// index, addr; ties by kind, owner. Kinds:
//   jumptable  every recovered switch table (`switchdataD_` data), owner = function referencing it;
//   libobj     a PsyQ obj signature (psx_ldr data/psyq/<ver>/*.json) anchored on a psx_ldr-applied symbol
//              and re-verified against memory (masked compare, in memory only), owner = <lib>/<obj>;
//   libobj?    a psx_ldr IMPORTED exe function no verified obj covers, owner = function name.
// Prints `unresolved computed jumps: N` (jr non-ra with no COMPUTED_JUMP reference). Never byte values.
// @category mmx5
import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.util.*;

import com.google.gson.*;

import ghidra.app.script.GhidraScript;
import ghidra.framework.Application;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;

public class ExportBoundaries extends GhidraScript {
	record Line(int space, long start, long end, String kind, String owner, String evidence) {}

	final List<Line> lines = new ArrayList<>();

	static int spaceIdx(Address a) {
		AddressSpace s = a.getAddressSpace();
		return s.isOverlaySpace() ? Integer.parseInt(s.getName().substring(3)) : -1;
	}

	void add(Address a, long len, String kind, String owner, String ev) {
		lines.add(new Line(spaceIdx(a), a.getOffset(), a.getOffset() + len, kind, owner, ev));
	}

	@Override
	protected void run() throws Exception {
		Listing listing = currentProgram.getListing();
		ReferenceManager rm = currentProgram.getReferenceManager();
		SymbolTable st = currentProgram.getSymbolTable();

		// jumptables
		for (Symbol s : st.getAllSymbols(true)) {
			if (!s.getName().startsWith("switchdataD_") || !s.getAddress().isMemoryAddress()) continue;
			// The table's namespace `switchD_<jr>` holds a `switchD` label on the jr instruction.
			Address jr = null;
			for (Symbol x : st.getSymbols(s.getParentNamespace())) {
				// same space: overlay switchD_ namespaces are named by offset and may be shared
				if (x.getName().equals("switchD")
					&& x.getAddress().getAddressSpace() == s.getAddress().getAddressSpace()) jr = x.getAddress();
			}
			Set<Long> targets = new HashSet<>();
			if (jr != null) {
				for (Reference r : rm.getReferencesFrom(jr)) {
					if (r.getReferenceType() == RefType.COMPUTED_JUMP) targets.add(r.getToAddress().getOffset());
				}
			}
			// Entries run while each word is one of the jr's computed-jump targets (read in memory only).
			Address a = s.getAddress();
			int n = 1;
			while (targets.contains(wordAt(a.add(4L * n))) && !isTable(st, a.add(4L * n))) n++;
			Function f = jr == null ? null : getFunctionContaining(jr);
			add(a, 4L * n, "jumptable", f != null ? f.getName()
				: jr == null ? "no-jr" : String.format("nofn@%08X", jr.getOffset()),
				"ghidra switch table, " + n + " entries, jr " + (jr == null ? "?" : String.format("%08X", jr.getOffset())));
		}
		int unresolved = 0;
		for (Instruction in : listing.getInstructions(currentProgram.getMemory(), true)) { // all spaces
			if (!in.getMnemonicString().endsWith("jr")) continue;
			Object[] op = in.getOpObjects(0);
			if (op.length == 1 && op[0].toString().equals("ra")) continue;
			boolean resolved = false;
			for (Reference r : in.getReferencesFrom()) {
				if (r.getReferenceType() == RefType.COMPUTED_JUMP) resolved = true;
			}
			if (!resolved) unresolved++;
		}

		// libobj: obj signatures anchored on psx_ldr-applied symbols (exe space only)
		AddressSpace exe = currentProgram.getAddressFactory().getDefaultAddressSpace();
		String ver = currentProgram.getOptions("Program Information").getString("PsyQ Version", "").replace(".", "");
		File dir = Application.getModuleDataSubDirectory("ghidra_psx_ldr", "psyq/" + ver).getFile(false);
		File[] files = dir.listFiles((d, n) -> n.endsWith(".json") && !n.equals("patches.json"));
		Arrays.sort(files);
		AddressSet covered = new AddressSet();
		for (File file : files) {
			String lib = file.getName().replace(".json", "");
			for (JsonElement e : JsonParser.parseString(Files.readString(file.toPath(), StandardCharsets.UTF_8))
					.getAsJsonArray()) {
				JsonObject t = e.getAsJsonObject();
				if (!t.has("sig")) continue;
				String obj = t.get("name").getAsString(), sig = t.get("sig").getAsString();
				String pre = obj.replace(".", "_") + "_";
				TreeSet<Long> bases = new TreeSet<>();
				for (JsonElement le : t.getAsJsonArray("labels")) {
					String ln = le.getAsJsonObject().get("name").getAsString();
					if (ln.isEmpty()) continue;
					ln = ln.replace("text_", pre).replace("loc_", pre);
					for (Symbol s : st.getGlobalSymbols(ln)) {
						if (s.getAddress().getAddressSpace() == exe && s.getSource() != SourceType.DEFAULT) {
							bases.add(s.getAddress().getOffset() - le.getAsJsonObject().get("offset").getAsInt());
						}
					}
				}
				for (long b : bases) {
					Address a = exe.getAddress(b);
					if (!sigMatches(a, sig)) continue;
					add(a, sig.length() / 3, "libobj", lib + "/" + obj,
						"psx_ldr psyq" + ver + " obj sig, symbol-anchored, masked match re-verified");
					covered.add(a, a.add(sig.length() / 3 - 1));
				}
			}
		}
		for (Function f : listing.getFunctions(exe.getMinAddress(), true)) {
			if (f.getEntryPoint().getAddressSpace() != exe || f.getSymbol().getSource() != SourceType.IMPORTED) continue;
			if (f.getEntryPoint().getOffset() < 0x80000000L) continue; // GTE macro space, not RAM
			if (covered.contains(f.getEntryPoint())) continue;
			AddressSetView body = f.getBody();
			add(f.getEntryPoint(), body.getMaxAddress().subtract(f.getEntryPoint()) + 1, "libobj?", f.getName(),
				"psx_ldr IMPORTED fn; no obj sig re-verified here (loader keeps no obj name per symbol)");
		}

		lines.sort(Comparator.comparingInt(Line::space).thenComparingLong(Line::start)
				.thenComparing(Line::kind).thenComparing(Line::owner).thenComparingLong(Line::end));
		try (Writer w = new OutputStreamWriter(new FileOutputStream(getScriptArgs()[0]), StandardCharsets.UTF_8)) {
			for (Line l : lines) {
				w.write(String.format("%s%08X-%08X | %s | %s | %s\n",
					l.space() < 0 ? "" : String.format("ovl%02d:", l.space()), l.start(), l.end(), l.kind(),
					l.owner(), l.evidence()));
			}
		}
		println("boundaries: " + lines.size() + " lines; unresolved computed jumps: " + unresolved);
	}

	static boolean isTable(SymbolTable st, Address a) {
		for (Symbol s : st.getSymbols(a)) {
			if (s.getName().startsWith("switchdataD_")) return true;
		}
		return false;
	}

	/** 32-bit little-endian word at a, or -1 when unreadable (compared in memory only, never written). */
	long wordAt(Address a) {
		try {
			return currentProgram.getMemory().getInt(a) & 0xFFFFFFFFL;
		}
		catch (Exception ex) {
			return -1;
		}
	}

	/** Masked compare of the obj signature against program memory (nothing is written out). */
	boolean sigMatches(Address a, String sig) {
		int n = sig.length() / 3;
		byte[] mem = new byte[n];
		try {
			if (currentProgram.getMemory().getBytes(a, mem) != n) return false;
		}
		catch (Exception ex) {
			return false;
		}
		for (int i = 0; i < n; i++) {
			char c1 = sig.charAt(3 * i), c2 = sig.charAt(3 * i + 1);
			int hi = mem[i] >> 4 & 0xF, lo = mem[i] & 0xF;
			if (c1 != '?' && Character.digit(c1, 16) != hi) return false;
			if (c2 != '?' && Character.digit(c2, 16) != lo) return false;
		}
		return true;
	}
}
