extern void f(int);
int lever_hoist(const int *p, int n) { int s = 0, i; for (i = 0; i < n; i++) { s += *p; f(i); } return s; }
