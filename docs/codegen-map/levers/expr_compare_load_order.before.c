/* Lever expr_compare_load_order (before): field written first in the compare -> field lh issued before the
   global's lh. */
struct S { int pad; short y; unsigned char f; };
extern short G;
extern void g(struct S *, int);
void lever_cmp(struct S *s)
{
    g(s, 2);
    if (s->y < G) {
        s->f = 0x40;
    } else {
        s->f = 0;
    }
}
