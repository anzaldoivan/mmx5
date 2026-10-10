/* Lever regalloc_decl_tie (before): a, b both 2 refs over 7 insns -> equal density (2857).
   Tie-break is allocno number = pseudo number = DECLARATION order: a declared first -> $s0. */
extern int g(void);
extern int h(int, int);
int lever_alloc_tie(int x, int y)
{
    int a, b;
    a = x + 3;
    b = y + 5;
    if (x)
        g();
    g();
    return h(a, b);
}
