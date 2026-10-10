// RecordPsyq.java -- postScript for tools/ghidra/import.sh: prints the loader-detected PsyQ version.
// @category mmx5
import ghidra.app.script.GhidraScript;

public class RecordPsyq extends GhidraScript {
	@Override
	protected void run() throws Exception {
		String v = currentProgram.getOptions("Program Information").getString("PsyQ Version", null);
		println("PsyQ Version: " + (v == null ? "" : v));
	}
}
