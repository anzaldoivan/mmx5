/* Lever sched_stmt_order (after): the same statements in the target's order; the stores follow it. */
void lever_order(int *p, int a, int b, int c) { p[0] = a + 2; p[1] = b + 3; p[2] = c + 1; }
