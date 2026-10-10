/* Lever cond_ternary_abs_window (after): the window test as one condition ternary;
   negative arm out of line (bltz), one store tail. */
void lever_abswin(char *p, int a, int b, int lim)
{
    int d;
    d = a - b;
    if ((d >= 0) ? (d <= lim) : (b - a <= lim)) {
        p[5] = 4;
        p[6] = 0;
    }
}
