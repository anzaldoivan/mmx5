int A, B;
extern void f(void);
void d2(int x, int y) { A = y; if (x) f(); B = 1; }
