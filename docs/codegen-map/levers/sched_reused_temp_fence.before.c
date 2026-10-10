/* Lever sched_reused_temp_fence (before): u16 reused temps. Each use zero-extends through a fresh
   SImode temp, the shared HI vars vanish, the four loads are independent and sched1 batches them. */
int lever_fence(unsigned short *p, unsigned short *q, int *o) {
  unsigned short w0, w1; int dx, dz;
  w0 = p[0]; w1 = q[0]; dx = w0 - w1; w0 = p[2]; w1 = q[2]; dz = w0 - w1;
  o[0] = dx; o[1] = dz; return 0; }
