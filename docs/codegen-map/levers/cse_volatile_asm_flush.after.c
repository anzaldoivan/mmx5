/* Lever cse_volatile_asm_flush (after): an operand-less, clobber-less asm is a raw volatile ASM_OPERANDS;
   cse flushes its whole table there → the second x * 5 + 1 is recomputed. Basic asm("") and an asm with a
   "memory" clobber do not flush register classes. Zero bytes emitted. */
int lever_vasm(int x) { int a = x * 5 + 1; __asm__ __volatile__("" : : ); return a ^ ((x * 5 + 1) << 3); }
