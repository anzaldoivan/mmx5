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
