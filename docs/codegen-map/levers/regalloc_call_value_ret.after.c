/* Lever regalloc_call_value_ret (after): callee declared int, result unused -> call_value insn
   sets $v0 (REG_UNUSED); local-alloc keeps $2 off the post-call temp, which moves to $3. */
extern int g(short *, int);
void lever_callret(short *p)
{
    if (--p[0] == 0) {
        p[0] = 2;
    } else if (--p[1] == 0) {
        g(p, 1);
        p[1] = 5;
    }
}
