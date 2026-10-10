/* Lever fold_assoc_temp_block (after): e + 1 assigned to a temp local first -> fold sees C - e only,
   the +1 stays on the field: addu $4,$4,1. */
struct S { int pad; short e; };
extern short C;
extern int g(int);
int lever_fold(struct S *s)
{
    int e = s->e + 1;
    return g(C - e);
}
