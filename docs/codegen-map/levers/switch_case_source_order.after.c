/* Lever switch_case_source_order (after): case 2 written first -> case bodies are emitted in source order, so
   jump opt inverts the test into bne r,1 / bne r,2 and falls through into each body in turn. */
extern int f(int *);
extern unsigned char tbl[];
void lever_case(int *o)
{
    switch (f(o)) {
    case 2:
        o[1] = tbl[o[3]];
        o[2] = 0;
        break;
    case 1:
        o[1] = 5;
        o[2] = 0;
        return;
    }
    o[4] = 0;
}
