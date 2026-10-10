// ExportAnnotations.java -- headless: write the program's annotations as jsonl (arg 1 = output path).
// One JSON object per line, keys sorted, lines sorted by (addr 8-hex, kind, name), LF, trailing newline.
// Kinds: function, label (USER_DEFINED/IMPORTED sources only), comment (all five types),
// datatype (category /mmx5 only), bookmark (Note type only). Never byte values or instruction text.
// Schema: phase-ends/current/PHASE_PLAN.md Interfaces; round trip: tools/ghidra/roundtrip.sh.
// @category mmx5
import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

import com.google.gson.*;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;

public class ExportAnnotations extends GhidraScript {
	static final Gson GSON = new GsonBuilder().disableHtmlEscaping().serializeNulls().create();

	/** 8-hex offset; overlay-space addresses are space-qualified (`ovl22::800ee970`). */
	static String hex(Address a) {
		String h = String.format("%08x", a.getOffset());
		return a.getAddressSpace().isOverlaySpace() ? a.getAddressSpace().getName() + "::" + h : h;
	}

	static boolean userSourced(SourceType s) {
		return s == SourceType.USER_DEFINED || s == SourceType.IMPORTED;
	}

	/** Struct/typedef definition as a JSON tree; ImportAnnotations.build() is its inverse. */
	static JsonObject def(DataType dt) {
		JsonObject o = new JsonObject();
		if (dt instanceof Structure s) {
			o.addProperty("kind", "struct");
			o.addProperty("size", s.isZeroLength() ? 0 : s.getLength());
			JsonArray fs = new JsonArray();
			for (DataTypeComponent c : s.getDefinedComponents()) {
				JsonObject f = new JsonObject();
				f.addProperty("off", c.getOffset());
				f.addProperty("len", c.getLength());
				f.addProperty("name", c.getFieldName());
				f.addProperty("type", c.getDataType().getPathName());
				f.addProperty("comment", c.getComment());
				fs.add(f);
			}
			o.add("fields", fs);
		}
		else if (dt instanceof TypeDef t) {
			o.addProperty("kind", "typedef");
			o.addProperty("type", t.getDataType().getPathName());
		}
		else {
			throw new IllegalArgumentException("unsupported /mmx5 datatype: " + dt.getPathName());
		}
		return o;
	}

	@Override
	protected void run() throws Exception {
		String out = getScriptArgs()[0];
		List<JsonObject> rows = new ArrayList<>();
		Listing listing = currentProgram.getListing();
		SymbolTable st = currentProgram.getSymbolTable();

		for (Function f : listing.getFunctions(true)) {
			if (!userSourced(f.getSymbol().getSource())) continue;
			JsonObject o = row("function", hex(f.getEntryPoint()), f.getName());
			o.addProperty("sig", f.getPrototypeString(false, false));
			rows.add(o);
		}
		for (Symbol s : st.getAllSymbols(true)) {
			if (s.getSymbolType() != SymbolType.LABEL || !s.getAddress().isMemoryAddress()) continue;
			if (!userSourced(s.getSource())) continue;
			JsonObject o = row("label", hex(s.getAddress()), s.getName());
			Data d = listing.getDefinedDataAt(s.getAddress());
			o.addProperty("type", d == null ? null : d.getDataType().getPathName());
			rows.add(o);
		}
		for (CommentType ct : CommentType.values()) {
			for (Address a : listing.getCommentAddressIterator(ct, currentProgram.getMemory(), true)) {
				String t = listing.getComment(ct, a);
				if (t == null) continue;
				JsonObject o = row("comment", hex(a), null);
				o.remove("name");
				o.addProperty("ctype", ct.name().toLowerCase());
				o.addProperty("text", t);
				rows.add(o);
			}
		}
		CategoryPath cat = new CategoryPath("/mmx5");
		Category c = currentProgram.getDataTypeManager().getCategory(cat);
		if (c != null) {
			for (DataType dt : c.getDataTypes()) {
				JsonObject o = row("datatype", "", dt.getName());
				o.add("def", def(dt));
				rows.add(o);
			}
		}
		Iterator<Bookmark> bi = currentProgram.getBookmarkManager().getBookmarksIterator(BookmarkType.NOTE);
		while (bi.hasNext()) {
			Bookmark b = bi.next();
			JsonObject o = row("bookmark", hex(b.getAddress()), b.getCategory());
			o.addProperty("text", b.getComment());
			rows.add(o);
		}

		// Sort on (addr, kind, name), then the full line as a fixed tie-break (e.g. comment ctypes).
		rows.sort(Comparator.<JsonObject, String> comparing(o -> str(o, "addr"))
				.thenComparing(o -> str(o, "kind"))
				.thenComparing(o -> str(o, "name"))
				.thenComparing(o -> GSON.toJson(sortKeys(o))));
		try (Writer w = new OutputStreamWriter(new FileOutputStream(out), StandardCharsets.UTF_8)) {
			for (JsonObject o : rows) w.write(GSON.toJson(sortKeys(o)) + "\n");
		}
		println("exported " + rows.size() + " annotations to " + out);
	}

	static String str(JsonObject o, String k) {
		JsonElement e = o.get(k);
		return e == null || e.isJsonNull() ? "" : e.getAsString();
	}

	static JsonObject row(String kind, String addr, String name) {
		JsonObject o = new JsonObject();
		o.addProperty("kind", kind);
		o.addProperty("addr", addr);
		o.addProperty("name", name);
		return o;
	}

	static JsonElement sortKeys(JsonElement e) {
		if (e.isJsonObject()) {
			JsonObject o = new JsonObject();
			new TreeMap<>(e.getAsJsonObject().asMap()).forEach((k, v) -> o.add(k, sortKeys(v)));
			return o;
		}
		if (e.isJsonArray()) {
			JsonArray a = new JsonArray();
			for (JsonElement x : e.getAsJsonArray()) a.add(sortKeys(x));
			return a;
		}
		return e;
	}
}
