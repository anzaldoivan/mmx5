/* Lever loop_rev_ne_vtop (after): the same loop as a guarded do-while has no LOOP_VTOP note, so the NE
   reversal is unavailable and the variable bound blocks the GE one: i counts up, endtest `slt i,n`. */
int lever_rev_ne(int *a, int n) { int s = 0, i = 0; if (n > 0) do s += a[i]; while (++i < n); return s; }
