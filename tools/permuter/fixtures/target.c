/* permute.py --selftest target (ROM-free): a tiny function of our own. */
int fixture_fn(int a, int b, int c) {
    if (a < b) {
        return a * c + b;
    }
    return (a - b) * c;
}
