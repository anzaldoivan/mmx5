/* Lever fold_abs_per_arm (after): ABS(a-b) in each arm -> the negation folds to
   subu d,b,a (operands swapped); no subu d,$0,d. */
#define ABS(x) ((x) < 0 ? -(x) : (x))
void lever_absarm(int *p, int c, int a, int b, int e, int f)
{
    if (c) {
        p[0] = ABS(a - b);
    } else {
        p[0] = ABS(e - f);
    }
}
