/* Lever expr_commutative_rtl_order (after): the u16 field read in place (zero_extend mem) as the left operand
   -> addu $3,$6,$3; CSE still loads the field once. */
struct S { int pad; unsigned short e; unsigned char *p; };
void lever_addu(struct S *s)
{
    unsigned char *p = s->p;
    int e = s->e;
    s->e = (-(p[3] + (s->e + (signed char)p[1])) & 0xF) + e;
}
