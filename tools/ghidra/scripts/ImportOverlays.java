// ImportOverlays.java -- postScript for tools/ghidra/import.sh: one overlay block `ovlNN` per
// docs/oracle/loadmap.json overlay with kind "code" and a dest, bytes from extracted/retail/ROCK_X5.BIN
// (bin_offset/size in bytes), then auto-analysis of the new blocks. Null-dest code overlays are skipped
// (printed). Arg `noanalysis` skips the analysis (roundtrip rebuild). Prints `overlays loaded: N`.
// Never writes bytes anywhere but the (ignored) Ghidra project.
// @category mmx5
import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;

import com.google.gson.*;

import ghidra.app.plugin.core.analysis.AutoAnalysisManager;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.mem.MemoryBlock;

public class ImportOverlays extends GhidraScript {
	@Override
	protected void run() throws Exception {
		// scripts/ -> ghidra/ -> tools/ -> repo root
		File root = getSourceFile().getParentFile().getParentFile().getParentFile().getParentFile().getFile(false);
		JsonObject lm = JsonParser.parseString(Files.readString(
			new File(root, "docs/oracle/loadmap.json").toPath(), StandardCharsets.UTF_8)).getAsJsonObject();
		AddressSet added = new AddressSet();
		int n = 0;
		try (RandomAccessFile bin = new RandomAccessFile(new File(root, "extracted/retail/ROCK_X5.BIN"), "r")) {
			for (JsonElement e : lm.getAsJsonArray("overlays")) {
				JsonObject o = e.getAsJsonObject();
				int idx = o.get("index").getAsInt();
				if (!"code".equals(o.get("kind").getAsString())) continue;
				if (o.get("dest").isJsonNull()) {
					println("overlay skipped: " + idx + " dest=null");
					continue;
				}
				byte[] buf = new byte[o.get("size").getAsInt()];
				bin.seek(o.get("bin_offset").getAsLong());
				bin.readFully(buf);
				MemoryBlock b = currentProgram.getMemory().createInitializedBlock(String.format("ovl%02d", idx),
					toAddr(Long.parseLong(o.get("dest").getAsString(), 16)), new ByteArrayInputStream(buf),
					buf.length, monitor, true);
				b.setRead(true);
				b.setExecute(true);
				added.add(b.getStart(), b.getEnd());
				n++;
			}
		}
		if (!java.util.Arrays.asList(getScriptArgs()).contains("noanalysis")) {
			AutoAnalysisManager mgr = AutoAnalysisManager.getAnalysisManager(currentProgram);
			mgr.reAnalyzeAll(added);
			mgr.startAnalysis(monitor);
		}
		println("overlays loaded: " + n);
	}
}
