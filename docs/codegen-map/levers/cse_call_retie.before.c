/* Lever cse_call_retie (before): x & 0xffff used before and after calls. cse keeps the pseudo-held class
   across the calls (only call-clobbered hard regs are invalidated) → computed once, parked in $s0. */
extern void f(int);
extern void g(void);
void lever_cse(int x) { f(x & 0xffff); g(); f(x & 0xffff); }
