/* Lever sched_birth_boost (before): k is set twice (REG_N_SETS 2), so sched1's birthing boost skips it;
   the first k chain (addu+sw) stays unboosted and lands at the head of the block. */
void lever_boost(int *p, int a, int b) {
  int k;
  k = b + 7;
  p[0] = a + 1; p[1] = a + 2; p[2] = a + 3;
  p[3] = k;
  k = b + 9;
  p[4] = k;
}
