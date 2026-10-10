/* Lever expr_mult_first_sum (before): p[i] → address (plus (mult i 4) p); expansion puts the MULT first, so
   the shifted index is the add's first operand and its register takes the sum. */
int lever_scale(int *p, int i) { return p[i]; }
