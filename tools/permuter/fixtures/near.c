/* permute.py --selftest draft: a near-miss of fixtures/target.c (distributed product, no shared temp). */
int fixture_fn(int a, int b, int c) {
    if (b > a) {
        return c * a + b;
    }
    return a * c - b * c;
}
