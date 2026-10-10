/* Lever cse_call_retie (after): a zero-byte input-tied re-tie re-SETs x between the occurrences → every class
   expression built from x is stale → x is kept in $s0 and the andi is recomputed at each use. */
extern void f(int);
extern void g(void);
void lever_cse(int x) { f(x & 0xffff); g(); __asm__("" : "=r"(x) : "0"(x)); f(x & 0xffff); }
