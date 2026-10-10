/* Lever expr_mult_first_sum (after): explicit shift through a byte pointer → (plus p (reg)); no MULT to put
   first, the base is the first operand and its register takes the sum. (i * 4 instead of i << 2 keeps the
   before codegen; a pointer local int *q = p + i; q[0] gives this after codegen too, see cse_expr.md.) */
int lever_scale(int *p, int i) { return *(int *)((char *)p + (i << 2)); }
