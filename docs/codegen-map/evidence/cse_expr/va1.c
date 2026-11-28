extern int *gp;
int lever_vasm(int *p) { int a = p[1]; gp[0] = 0; return a + p[1]; }
