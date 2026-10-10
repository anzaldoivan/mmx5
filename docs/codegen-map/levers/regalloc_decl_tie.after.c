/* Lever regalloc_decl_tie (after): statements unchanged, declarations swapped -> b takes $s0.
   Works only on an exact density tie; unequal densities are decl-order stable. */
extern int g(void);
extern int h(int, int);
int lever_alloc_tie(int x, int y)
{
    int b, a;
    a = x + 3;
    b = y + 5;
    if (x)
        g();
    g();
    return h(a, b);
}
