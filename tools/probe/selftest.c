/* Planted control for `probe.py --selftest`: our own C, a call and a divide. */
extern int helper(int);

int selftest(int a, int b) {
    int q = helper(a) / b;
    return q + a % 7;
}
