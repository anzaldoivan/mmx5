/* Lever div_pow2_signed (after): x >> 2 (floor, not truncation, for x < 0); no bias branch, a single sra.
   Use where the source can be shown to shift, or the dividend is known non-negative. */
int lever_div(int x) { return x >> 2; }
