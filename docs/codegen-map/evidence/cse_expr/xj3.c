void lever_xjump(int a, int *p, int b)
{
    if (a) { p[0] = a + 3; p[2] = b; p[3] = b; }
    else   { p[1] = b + 7; p[2] = b; p[3] = b; }
}
