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
