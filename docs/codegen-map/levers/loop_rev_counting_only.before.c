/* Lever loop_rev_counting_only (before): counter used only for counting; check_dbra_loop normalizes the
   nonzero start (2.95.2; 2.7.2 required start 0) and reverses even with a call: `li 8 ... bgez`. */
extern void lever_ext(int);
void lever_rev_count(void) { int i; for (i = 1; i < 10; i++) lever_ext(0); }
