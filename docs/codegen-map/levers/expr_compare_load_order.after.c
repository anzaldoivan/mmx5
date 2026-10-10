/* Lever expr_compare_load_order (after): same test written global-first (G > s->y) -> compare expands op0
   first, the global's lh moves ahead of the field load. */
struct S { int pad; short y; unsigned char f; };
extern short G;
extern void g(struct S *, int);
void lever_cmp(struct S *s)
{
    g(s, 2);
    if (G > s->y) {
        s->f = 0x40;
    } else {
        s->f = 0;
    }
}
