extern void g(int, int, int);
void lever_iv(char *q, int n) { int i; for (i = 0; i < n; i++) { g(*(int *)q, *(int *)(q + 8), *(int *)(q + 20)); q += 32; } }
