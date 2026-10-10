// CreateOverlayFunctions.java -- postScript for tools/ghidra/import.sh (after ImportOverlays, before
// ExportBoundaries): in every overlay block `ovlNN`, creates functions (default FUN_ names, never
// USER_DEFINED, so the annotations export is unchanged) at (a) call targets landing in the block, then
// (b) for each non-ra jr outside any function: the start found by walking back to just after the previous
// `jr ra` + delay slot, a function body, defined data or the block start, skipping zero padding forward. Addresses are
// processed sorted per block; then auto-analysis runs on the changes. Prints `overlay functions: +N`.
// Exe pass: (b) in block CODE, kept only where the start has a DATA/PARAM ref; iterated to a fixpoint
// with analysis between rounds. Prints `exe functions: +N`.
// Reads words in memory only; writes nothing outside the (ignored) Ghidra project.
// @category mmx5
import java.util.*;

import ghidra.app.cmd.function.CreateFunctionCmd;
import ghidra.app.plugin.core.analysis.AutoAnalysisManager;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.RefType;
import ghidra.program.model.symbol.Reference;

public class CreateOverlayFunctions extends GhidraScript {
	static final long JR_RA = 0x03E00008L;

	int created = 0;

	@Override
	protected void run() throws Exception {
		Listing listing = currentProgram.getListing();
		MemoryBlock[] blocks = currentProgram.getMemory().getBlocks();
		Arrays.sort(blocks, Comparator.comparing(MemoryBlock::getName));
		for (MemoryBlock b : blocks) {
			if (!b.getName().matches("ovl\\d+") || !b.getStart().getAddressSpace().isOverlaySpace()) continue;
			AddressSet set = new AddressSet(b.getStart(), b.getEnd());
			// (a) call targets in this block
			TreeSet<Address> calls = new TreeSet<>();
			for (Instruction in : listing.getInstructions(set, true)) {
				for (Reference r : in.getReferencesFrom()) {
					if (r.getReferenceType().isCall() && set.contains(r.getToAddress())) calls.add(r.getToAddress());
				}
			}
			for (Address a : calls) make(a);
			// (b) jr not inside a function: walk back to the previous jr ra + delay slot
			for (Address jr : orphanJrs(listing, set)) {
				if (getFunctionContaining(jr) == null) make(walkBack(jr, b));
			}
		}
		AutoAnalysisManager mgr = AutoAnalysisManager.getAnalysisManager(currentProgram);
		mgr.startAnalysis(monitor);
		println("overlay functions: +" + created);
		// exe pass: same walk-back in the exe CODE block, but only where the entry is DATA/PARAM-referenced
		// (fn-pointer-only code); repeated with analysis until no new function (fixpoint), ascending order.
		int exe = 0;
		for (MemoryBlock b : blocks) {
			if (!b.getName().equals("CODE") || b.getStart().getAddressSpace().isOverlaySpace()) continue;
			AddressSet set = new AddressSet(b.getStart(), b.getEnd());
			for (int round = created; ; round = created) {
				for (Address jr : orphanJrs(listing, set)) {
					if (getFunctionContaining(jr) != null) continue;
					Address s = walkBack(jr, b);
					if (dataRefd(s)) make(s);
				}
				if (created == round) break;
				exe += created - round;
				mgr.startAnalysis(monitor);
			}
		}
		println("exe functions: +" + exe);
	}

	/** Non-ra jr instructions in set, ascending. */
	List<Address> orphanJrs(Listing listing, AddressSet set) {
		List<Address> jrs = new ArrayList<>();
		for (Instruction in : listing.getInstructions(set, true)) {
			if (!in.getMnemonicString().endsWith("jr")) continue;
			Object[] op = in.getOpObjects(0);
			if (op.length == 1 && op[0].toString().equals("ra")) continue;
			jrs.add(in.getAddress());
		}
		return jrs;
	}

	/** Start of the code holding jr: just after the previous jr ra + delay slot, a function body,
	 *  defined data or the block start, skipping zero padding forward. */
	Address walkBack(Address jr, MemoryBlock b) {
		Listing listing = currentProgram.getListing();
		Address s = jr;
		while (s.subtract(b.getStart()) >= 4) {
			Address p = s.subtract(4);
			if (getFunctionContaining(p) != null) break;
			// defined data (e.g. a switch table placed before the code) also bounds the walk
			if (getInstructionAt(p) == null && !listing.isUndefined(p, p.add(3))) break;
			if (p.subtract(b.getStart()) >= 4 && wordAt(p.subtract(4)) == JR_RA) break;
			s = p;
		}
		while (s.compareTo(jr) < 0 && wordAt(s) == 0) s = s.add(4);
		return s;
	}

	/** True when a DATA or PARAM reference points at a. */
	boolean dataRefd(Address a) {
		for (Reference r : getReferencesTo(a)) {
			RefType t = r.getReferenceType();
			if (t.isData() || t == RefType.PARAM) return true;
		}
		return false;
	}
	void make(Address a) {
		if (getFunctionAt(a) != null || getFunctionContaining(a) != null) return;
		if (getInstructionAt(a) == null) {
			if (getDataAt(a) != null || !disassemble(a)) return;
		}
		if (new CreateFunctionCmd(a).applyTo(currentProgram, monitor)) created++;
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
}
