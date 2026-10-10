/* Lever loop_const_hoist (before): a call in the loop sets unknown_address_altered, so the plain global
   K is not invariant and is reloaded every iteration (`lw $2,%lo(K)` at the loop head). */
extern void lever_ext(int);
extern int K;
int lever_hoist(int n) { int s = 0, i; for (i = 0; i < n; i++) { s += K; lever_ext(i); } return s; }
