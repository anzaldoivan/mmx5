/* Lever alias_struct_grant (before): the store goes through a cast on top of a byte sum, which denies `/s`
   (cse_expr.md K§4c); a non-`/s` varying store may alias the fixed scalar `g`, so the load of `g` stays below it. */
int g;
int lever_alias(int *p, int v) { *(int *)((char *)p + 4) = v; return g + v; }
