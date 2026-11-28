void lever_xjump(int a, int *p)
{
    if (a) { p[0] = a + 3; p[2] = 5; }
    else   { p[1] = 7;     p[2] = 5; }
}
