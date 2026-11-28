extern int g; extern void f(void);
void lever_prom(int *a, int n) { int i; for (i = 0; i < n; i++) { g += a[i]; f(); } }
