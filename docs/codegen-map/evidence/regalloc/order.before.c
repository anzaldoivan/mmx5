extern int g(void);
int lever_alloc_order(int x, int y)
{
    int a = x + 1;
    int b = y + 2;
    g();
    return a * a * a + b;
}
