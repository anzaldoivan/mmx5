/* Lever expr_byte_ptr_scale (before): a scaffold byte offset added to a typed pointer; pointer_int_sum scales it
   again by sizeof(int), so the index is shifted by 4 (x16) where the target shifts by 2. */
int lever_x4(int *p, int i) { return *(p + (i << 2)); }
