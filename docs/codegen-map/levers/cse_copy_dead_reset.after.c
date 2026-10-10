/* Lever cse_copy_dead_reset (after): a dead second store to q (deleted later by flow) stops cse from
   substituting q for p past it; p survives in $s, q stays a short-lived temp, `move $s,$t` copies. */
extern void g(int);
void lever_deadset(unsigned char *a, unsigned char *t)
{
    unsigned char *p, *q;
    q = a + 0x80;
    q[4] = a[0x84] - 1;
    p = q;
    if (q[4] == 0) {
        a[0x84] = 2;
        q = t + 0x47;
        t[0x5C] = t[0x47] + 1;
        g(0);
        p[3] = a[0x83] - 1;
    }
}
