/* Lever loop_rev_counting_only (after): the counter is also an argument, so it is not counting-only and the
   call blocks the general reversal: up-count `addu 1; slt ...,10; bne`. */
extern void lever_ext(int);
void lever_rev_count(void) { int i; for (i = 1; i < 10; i++) lever_ext(i); }
