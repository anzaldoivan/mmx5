/* Lever regalloc_density_order (before): a has 6 refs over 11 insns, b 3 over 11 (.lreg).
   allocno_compare density floor_log2(n)*n/len: a 10909 > b 2727 -> a allocated first -> $s0 ($16). */
extern int g(int);
int lever_alloc_order(int x, int y)
{
    int a = x + 1;
    int b = y + 2;
    if (g(x))
        a = g(a);
    g(b);
    return a * a * a + b;
}
