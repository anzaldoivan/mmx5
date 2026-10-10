/* Lever div_pow2_signed (before): signed divide by a power of two.
   expand_divmod biases a negative dividend by d-1 before the arithmetic shift. */
int lever_div(int x) { return x / 4; }
