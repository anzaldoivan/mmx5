/* Lever loop_const_hoist (after): `const` marks the MEM unchanging; invariant_p accepts it before the
   unknown_address_altered test, so K is hoisted to the preheader (and s += K becomes a biv: pre-add /
   post-subtract compensation around the loop, kit L5 shape). */
extern void lever_ext(int);
extern const int K;
int lever_hoist(int n) { int s = 0, i; for (i = 0; i < n; i++) { s += K; lever_ext(i); } return s; }
