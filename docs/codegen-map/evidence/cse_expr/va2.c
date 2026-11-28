extern int *gp;
int lever_vasm(int *p) { int a = p[1] + 4; __asm__ __volatile__("" : : ); return a + (p[1] + 4) * 3; }
