int lever_vasm(int x) { int a = x * 5 + 1; __asm__ ("" : : ); return a ^ ((x * 5 + 1) << 3); }
