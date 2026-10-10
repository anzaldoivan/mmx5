/* Lever loop_rev_ne_vtop (before): a for loop is rotated by jump.c (exit test duplicated, LOOP_VTOP note);
   the index is counting-only once a[i] is strength-reduced, so check_dbra_loop reverses it onto NE:
   n itself counts down to 0 (`addu $5,$5,-1; bne $5,$0`). */
int lever_rev_ne(int *a, int n) { int s = 0, i; for (i = 0; i < n; i++) s += a[i]; return s; }
