// ApplySymbols.java -- headless: make each `<name>\t<addr>` row of a spec TSV (arg 1, written by
// tools/readability/mirror.py apply from config/symbols.*.txt) the primary symbol at its address, writing only
// differences (compare-before-write, as ImportAnnotations.java). A function is renamed; otherwise a stale
// user label is renamed, or the name is created as a label and made primary. Addr: 8-hex, or `ovlNN::8-hex`.
// Prints `mirror-apply: <n> names, <k> applied, <d> diffs, <e> errors`; each error as `mirror-error: ...`.
// Names and addresses only (G12).
// @category mmx5
import java.nio.charset.StandardCharsets;
import java.nio.file.*;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.*;

public class ApplySymbols extends GhidraScript {
	@Override
	protected void run() throws Exception {
		SymbolTable st = currentProgram.getSymbolTable();
		int n = 0, k = 0, d = 0, e = 0;
		for (String l : Files.readAllLines(Paths.get(getScriptArgs()[0]), StandardCharsets.UTF_8)) {
			if (l.isEmpty()) continue;
			String[] p = l.split("\t");
			String name = p[0];
			n++;
			try {
				Address a = p[1].contains("::") ? toAddr(p[1]) : toAddr(Long.parseLong(p[1], 16));
				if (a == null) throw new IllegalArgumentException("unresolved address");
				Symbol prim = st.getPrimarySymbol(a);
				if (prim != null && prim.getName().equals(name)) continue;
				Symbol same = st.getGlobalSymbol(name, a);
				Function f = getFunctionAt(a);
				if (f != null) {
					if (same != null) same.delete(); // a label of that name would collide with the rename
					f.setName(name, SourceType.USER_DEFINED);
				}
				else if (same != null) {
					same.setPrimary();
				}
				else if (prim != null && !prim.isDynamic() && prim.getSymbolType() == SymbolType.LABEL) {
					prim.setName(name, SourceType.USER_DEFINED); // overwrite the stale name
				}
				else {
					st.createLabel(a, name, SourceType.USER_DEFINED).setPrimary();
				}
				k++;
				prim = st.getPrimarySymbol(a);
				if (prim == null || !prim.getName().equals(name)) {
					d++;
					println("mirror-error: " + name + " " + p[1] + ": primary is " + (prim == null ? "<none>" : prim.getName()));
				}
			}
			catch (Exception x) {
				e++;
				println("mirror-error: " + name + " " + p[1] + ": " + x.getMessage());
			}
		}
		println("mirror-apply: " + n + " names, " + k + " applied, " + d + " diffs, " + e + " errors");
	}
}
