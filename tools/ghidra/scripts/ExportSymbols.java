// ExportSymbols.java -- headless, read-only: for each `<name>\t<addr>` row of a spec TSV (arg 1) write
// `<addr>\t<primary symbol name>` (`<none>` if no symbol, `<bad-addr>` if unresolved) to arg 2, spec order.
// Used by tools/readability/mirror.py check with -readOnly -noanalysis. Names and addresses only (G12).
// @category mmx5
import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.*;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.symbol.Symbol;

public class ExportSymbols extends GhidraScript {
	@Override
	protected void run() throws Exception {
		int n = 0;
		try (Writer w = new OutputStreamWriter(new FileOutputStream(getScriptArgs()[1]), StandardCharsets.UTF_8)) {
			for (String l : Files.readAllLines(Paths.get(getScriptArgs()[0]), StandardCharsets.UTF_8)) {
				if (l.isEmpty()) continue;
				String as = l.split("\t")[1];
				String name;
				try {
					Address a = as.contains("::") ? toAddr(as) : toAddr(Long.parseLong(as, 16));
					Symbol s = a == null ? null : currentProgram.getSymbolTable().getPrimarySymbol(a);
					name = a == null ? "<bad-addr>" : s == null ? "<none>" : s.getName();
				}
				catch (Exception x) {
					name = "<bad-addr>";
				}
				w.write(as + "\t" + name + "\n");
				n++;
			}
		}
		println("mirror-export: " + n + " names");
	}
}
