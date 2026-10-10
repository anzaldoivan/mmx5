/* Lever xjump_tail_merge (before): the shared tail statement written in each arm.
   jump2 first turns the then-arm's jump-to-epilogue into a RETURN; RETURN-to-RETURN cross-jumping needs a
   2-insn match, a 1-insn tail has 1 → both arms keep their own copy and their own return. */
void lever_xjump(int a, int *p, int b)
{
    if (a) { p[0] = a + 3; p[2] = b; }
    else   { p[1] = b + 7; p[2] = b; }
}
