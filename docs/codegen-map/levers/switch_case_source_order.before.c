/* Lever switch_case_source_order (before): case 1 written first -> beq/beq/j compare chain, case-1 body inline
   after the tests and the case-2 body reached by a taken branch. */
extern int f(int *);
extern unsigned char tbl[];
void lever_case(int *o)
{
    switch (f(o)) {
    case 1:
        o[1] = 5;
        o[2] = 0;
        return;
    case 2:
        o[1] = tbl[o[3]];
        o[2] = 0;
        break;
    }
    o[4] = 0;
}
