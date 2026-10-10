/* Lever alias_struct_grant (after): the typed index `p[1]` grants `/s` (same address, same `sw`); a varying `/s`
   store never conflicts with a fixed scalar (alias.c fixed_scalar_and_varying_struct_p), so the load of `g` floats up. */
int g;
int lever_alias(int *p, int v) { p[1] = v; return g + v; }
