extern int f(int, int);
extern int h(void);
int lever_boost(int x) { int r1, r2; r1 = f(x, 1); r2 = f(r1, h()); return f(r2, h()); }
