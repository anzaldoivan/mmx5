void lever_boost(int *p, int a, int b) {
  int k;
  k = b + 7;
  p[0] = a + 1; p[1] = a + 2; p[2] = a + 3;
  p[3] = k;
  k = b + 9;
  p[4] = k;
}
