/* permute.py / plateau.py --selftest rockx5 fixture (ROM-free): our own function with a call and a global read. */
extern int fixture_global;
extern int fixture_callee(int);

int fixture_reloc(int a) {
    return fixture_callee(a + fixture_global) + 3;
}
