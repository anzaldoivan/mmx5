int s12(unsigned short *p, unsigned short *q, int *o) {
  int dx, dz;
  dx = p[0] - q[0]; dz = p[2] - q[2];
  o[0] = dx; o[1] = dz; return 0; }
