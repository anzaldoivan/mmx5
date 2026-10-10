/* Lever sched_birth_boost (after): a fresh single-set local m for the second value; both defs are
   boosted (7f000001 in the sched dump) and sink next to their stores. */
void lever_boost(int *p, int a, int b) {
  int k, m;
  k = b + 7;
  p[0] = a + 1; p[1] = a + 2; p[2] = a + 3;
  p[3] = k;
  m = b + 9;
  p[4] = m;
}
