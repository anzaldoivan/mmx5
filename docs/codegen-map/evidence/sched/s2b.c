extern int f(int, int);
extern int h(void);
int lever_boost(int x) { int r; r = f(x, 1); r = f(r, h()); r = f(r, h()); return r; }
