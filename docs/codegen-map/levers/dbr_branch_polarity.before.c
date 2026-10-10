/* Lever dbr_branch_polarity (before): if (c == 0) a+1 else a+2. dbr's eager fill puts the a+2 arm
   in the branch slot (dest $2 is dead on the opposite path: the fallthrough overwrites it). */
int lever_polarity(int c, int a) { int r; if (c == 0) r = a + 1; else r = a + 2; return r; }
