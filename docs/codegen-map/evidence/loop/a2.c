int lever_sum(int *a, int n) { int s = 0; int *e = a + n; for (; a < e; a++) s += *a; return s; }
