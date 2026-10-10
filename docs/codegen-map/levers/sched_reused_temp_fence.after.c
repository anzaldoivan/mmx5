/* Lever sched_reused_temp_fence (after): int reused temps survive as multi-set pseudos; the second
   pair's sets carry output/anti deps on the first pair, so loads pair up: lhu;lhu;subu twice. */
int lever_fence(unsigned short *p, unsigned short *q, int *o) {
  int w0, w1; int dx, dz;
  w0 = p[0]; w1 = q[0]; dx = w0 - w1; w0 = p[2]; w1 = q[2]; dz = w0 - w1;
  o[0] = dx; o[1] = dz; return 0; }
