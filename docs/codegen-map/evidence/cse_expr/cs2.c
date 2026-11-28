extern void f(int);
extern void g(void);
void lever_cse(int x) { f(x & 0xffff); g(); __asm__("" : "=r"(x) : "0"(x)); f(x & 0xffff); }
