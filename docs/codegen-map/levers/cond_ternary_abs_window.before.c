/* Lever cond_ternary_abs_window (before): |a-b| <= lim as nested if / else-if;
   the two compare arms cross-jump into a shared compare tail. */
void lever_abswin(char *p, int a, int b, int lim)
{
    int d;
    d = a - b;
    if (d >= 0) {
        if (d <= lim) {
            p[5] = 4;
            p[6] = 0;
        }
    } else if (b - a <= lim) {
        p[5] = 4;
        p[6] = 0;
    }
}
