/* Lever regalloc_density_order (after): only the use count moves (a 4/12, b 5/10; 6666 < 10000).
   b now outranks a -> b takes $s0, a falls to $s1. The callee-saved bank follows density, not decl order. */
extern int g(int);
int lever_alloc_order(int x, int y)
{
    int a = x + 1;
    int b = y + 2;
    if (g(x))
        a = g(a);
    g(b);
    return a + b * b * b;
}
