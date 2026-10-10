/* Lever cse_volatile_asm_flush (before): x * 5 + 1 written twice; cse reuses the first value. */
int lever_vasm(int x) { int a = x * 5 + 1; return a ^ ((x * 5 + 1) << 3); }
