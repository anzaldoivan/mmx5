/* Lever fold_abs_per_arm (before): d = a-b per arm, one ABS after the join -> abssi2 insn;
   its template negates the difference: bgez d,1f / subu d,$0,d. */
#define ABS(x) ((x) < 0 ? -(x) : (x))
void lever_absarm(int *p, int c, int a, int b, int e, int f)
{
    int d;
    if (c) {
        d = a - b;
    } else {
        d = e - f;
    }
    p[0] = ABS(d);
}
