/* Lever regalloc_call_value_ret (before): callee declared void -> plain call insn;
   $v0 is free after the call, so the post-call constant temp takes $2. */
extern void g(short *, int);
void lever_callret(short *p)
{
    if (--p[0] == 0) {
        p[0] = 2;
    } else if (--p[1] == 0) {
        g(p, 1);
        p[1] = 5;
    }
}
