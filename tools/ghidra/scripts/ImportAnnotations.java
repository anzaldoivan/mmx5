// ImportAnnotations.java -- headless: apply an annotations jsonl (arg 1) to the program, writing only
// differences (never deletes what the file lacks). Inverse of ExportAnnotations.java; the headless run
// saves the program. Round trip: tools/ghidra/roundtrip.sh.
// @category mmx5
import java.nio.charset.StandardCharsets;
import java.nio.file.*;
import java.util.*;

import com.google.gson.*;

import ghidra.app.cmd.function.ApplyFunctionSignatureCmd;
import ghidra.app.script.GhidraScript;
import ghidra.app.services.DataTypeManagerService;
import ghidra.app.util.cparser.C.CParserUtils;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;

public class ImportAnnotations extends GhidraScript {
	int writes;

	@Override
	protected void run() throws Exception {
		List<JsonObject> rows = new ArrayList<>();
		for (String l : Files.readAllLines(Paths.get(getScriptArgs()[0]), StandardCharsets.UTF_8)) {
			if (!l.isEmpty()) rows.add(JsonParser.parseString(l).getAsJsonObject());
		}
		// Datatypes first: signatures and label types may name them.
		for (String kind : new String[] { "datatype", "function", "label", "comment", "bookmark" }) {
			for (JsonObject o : rows) {
				if (kind.equals(s(o, "kind"))) apply(kind, o);
			}
		}
		println("applied " + writes + " differences from " + rows.size() + " annotations");
	}

	static String s(JsonObject o, String k) {
		JsonElement e = o.get(k);
		return e == null || e.isJsonNull() ? null : e.getAsString();
	}

	void apply(String kind, JsonObject o) throws Exception {
		String as = s(o, "addr");
		Address a = kind.equals("datatype") ? null
			: as.contains("::") ? toAddr(as) : toAddr(Long.parseLong(as, 16)); // `ovl22::800ee970`
		Listing listing = currentProgram.getListing();
		switch (kind) {
			case "datatype" -> {
				DataTypeManager dtm = currentProgram.getDataTypeManager();
				DataType want = build(s(o, "name"), o.getAsJsonObject("def"));
				DataType have = dtm.getDataType(want.getDataTypePath());
				if (have == null || !have.isEquivalent(want)) {
					dtm.addDataType(want, DataTypeConflictHandler.REPLACE_HANDLER);
					writes++;
				}
			}
			case "function" -> {
				Function f = getFunctionAt(a);
				if (f == null) {
					if (getInstructionAt(a) == null) disassemble(a); // un-analysed overlay blocks (roundtrip)
					f = createFunction(a, s(o, "name"));
					writes++;
				}
				if (!f.getName().equals(s(o, "name"))) {
					f.setName(s(o, "name"), SourceType.USER_DEFINED);
					writes++;
				}
				if (!f.getPrototypeString(false, false).equals(s(o, "sig"))) {
					FunctionDefinitionDataType sig = CParserUtils.parseSignature(
						(DataTypeManagerService) null, currentProgram, s(o, "sig"), true);
					new ApplyFunctionSignatureCmd(a, sig, SourceType.USER_DEFINED).applyTo(currentProgram);
					writes++;
				}
			}
			case "label" -> {
				SymbolTable st = currentProgram.getSymbolTable();
				if (st.getGlobalSymbol(s(o, "name"), a) == null) {
					st.createLabel(a, s(o, "name"), SourceType.USER_DEFINED);
					writes++;
				}
				String type = s(o, "type");
				Data d = listing.getDefinedDataAt(a);
				if (type != null && (d == null || !d.getDataType().getPathName().equals(type))) {
					DataType dt = resolve(type);
					listing.clearCodeUnits(a, a.add(Math.max(dt.getLength(), 1) - 1), false);
					listing.createData(a, dt);
					writes++;
				}
			}
			case "comment" -> {
				CommentType ct = CommentType.valueOf(s(o, "ctype").toUpperCase());
				if (!Objects.equals(listing.getComment(ct, a), s(o, "text"))) {
					listing.setComment(a, ct, s(o, "text"));
					writes++;
				}
			}
			case "bookmark" -> {
				BookmarkManager bm = currentProgram.getBookmarkManager();
				Bookmark b = bm.getBookmark(a, BookmarkType.NOTE, s(o, "name"));
				if (b == null || !Objects.equals(b.getComment(), s(o, "text"))) {
					bm.setBookmark(a, BookmarkType.NOTE, s(o, "name"), s(o, "text"));
					writes++;
				}
			}
			default -> throw new IllegalArgumentException("unknown kind: " + kind);
		}
	}

	/** Inverse of ExportAnnotations.def(): struct or typedef in category /mmx5. */
	DataType build(String name, JsonObject def) throws Exception {
		DataTypeManager dtm = currentProgram.getDataTypeManager();
		CategoryPath cat = new CategoryPath("/mmx5");
		if ("typedef".equals(s(def, "kind"))) {
			return new TypedefDataType(cat, name, resolve(s(def, "type")), dtm);
		}
		StructureDataType st = new StructureDataType(cat, name, def.get("size").getAsInt(), dtm);
		for (JsonElement e : def.getAsJsonArray("fields")) {
			JsonObject f = e.getAsJsonObject();
			st.replaceAtOffset(f.get("off").getAsInt(), resolve(s(f, "type")), f.get("len").getAsInt(),
				s(f, "name"), s(f, "comment"));
		}
		return st;
	}

	/** Datatype by path name: the program's manager, then built-ins; a trailing " *" is a pointer. */
	DataType resolve(String path) {
		if (path.endsWith(" *")) {
			return new PointerDataType(resolve(path.substring(0, path.length() - 2)),
				currentProgram.getDataTypeManager());
		}
		DataType dt = currentProgram.getDataTypeManager().getDataType(path);
		if (dt == null) dt = BuiltInDataTypeManager.getDataTypeManager().getDataType(path);
		if (dt == null) throw new IllegalArgumentException("unresolved datatype: " + path);
		return dt;
	}
}
