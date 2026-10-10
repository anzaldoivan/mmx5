/* Lever sched_stmt_order (before): three independent latency-1 store chains, p[2] written first.
   All tie at priority 1; rank_for_schedule falls through to the LUID tie-break, so source order is the schedule. */
void lever_order(int *p, int a, int b, int c) { p[2] = c + 1; p[0] = a + 2; p[1] = b + 3; }
