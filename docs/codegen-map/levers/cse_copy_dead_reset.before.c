/* Lever cse_copy_dead_reset (before): q set once, p = q -> cse canon_reg substitutes q for every use
   of p and the copy dies; q itself lives in the callee-saved reg across the call. */
extern void g(int);
void lever_deadset(unsigned char *a, unsigned char *t)
{
    unsigned char *p, *q;
    q = a + 0x80;
    q[4] = a[0x84] - 1;
    p = q;
    if (q[4] == 0) {
        a[0x84] = 2;
        t[0x5C] = t[0x47] + 1;
        g(0);
        p[3] = a[0x83] - 1;
    }
}
