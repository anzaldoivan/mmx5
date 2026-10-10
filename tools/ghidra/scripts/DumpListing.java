// DumpListing.java -- headless: write the listing of the function containing <hex addr> (arg 1) to
// .run/ghidra-dump/<ADDR>.txt (scratch, never tracked: it holds game-derived bytes).
// Run with -process SLUS_013.34 -noanalysis -readOnly.
// @category mmx5
import java.io.File;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;

public class DumpListing extends GhidraScript {
	@Override
	protected void run() throws Exception {
		String arg = getScriptArgs()[0].toUpperCase();
		Address a = toAddr(Long.parseLong(arg, 16));
		Function f = getFunctionContaining(a);
		if (f == null) throw new IllegalArgumentException("no function contains " + arg);
		// scripts/ -> ghidra/ -> tools/ -> repo root
		File root = getSourceFile().getParentFile().getParentFile().getParentFile().getParentFile().getFile(false);
		File out = new File(root, ".run/ghidra-dump/" + arg + ".txt");
		out.getParentFile().mkdirs();
		Listing listing = currentProgram.getListing();
		try (PrintWriter w = new PrintWriter(out, StandardCharsets.UTF_8)) {
			w.println(f.getEntryPoint() + " " + f.getPrototypeString(false, false));
			for (CodeUnit cu : listing.getCodeUnits(f.getBody(), true)) {
				String eol = cu.getComment(CommentType.EOL);
				w.println(cu.getAddress() + "  " + cu + (eol == null ? "" : "  ; " + eol));
			}
		}
		println("wrote " + out);
	}
}
