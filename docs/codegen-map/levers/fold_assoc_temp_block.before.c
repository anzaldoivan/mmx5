/* Lever fold_assoc_temp_block (before): C - (e + 1) in one expression -> fold associates it to
   (C - 1) - e: addu $3,$3,-1 on the global. */
struct S { int pad; short e; };
extern short C;
extern int g(int);
int lever_fold(struct S *s)
{
    return g(C - (s->e + 1));
}
