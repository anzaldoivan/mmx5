/* Lever expr_byte_ptr_scale (after): cast through a byte pointer; char has size 1, so the byte offset is used as
   written and the index shift is the target's 2. */
int lever_x4(int *p, int i) { return *(int *)((char *)p + (i << 2)); }
