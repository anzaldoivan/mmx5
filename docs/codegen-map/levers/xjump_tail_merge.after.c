/* Lever xjump_tail_merge (after): the tail written once after the join → one copy, then-arm jumps over the
   else arm. (A 2-insn tail duplicated in both arms is cross-jumped into this same code.) */
void lever_xjump(int a, int *p, int b)
{
    if (a) { p[0] = a + 3; }
    else   { p[1] = b + 7; }
    p[2] = b;
}
