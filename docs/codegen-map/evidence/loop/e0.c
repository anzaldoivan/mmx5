extern void f(int); extern int K;
int lever_hoist(int n) { int s = 0, i; for (i = 0; i < n; i++) { s += K; f(i); } return s; }
