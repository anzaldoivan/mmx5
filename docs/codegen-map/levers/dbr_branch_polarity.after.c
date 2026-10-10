/* Lever dbr_branch_polarity (after): the same function with the test and arms flipped; the branch
   inverts and the other arm (a+1) fills the slot. */
int lever_polarity(int c, int a) { int r; if (c != 0) r = a + 2; else r = a + 1; return r; }
