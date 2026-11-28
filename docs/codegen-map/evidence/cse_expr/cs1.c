extern void f(int);
extern void g(void);
void lever_cse(int x) { f(x & 0xffff); g(); f(x & 0xffff); }
