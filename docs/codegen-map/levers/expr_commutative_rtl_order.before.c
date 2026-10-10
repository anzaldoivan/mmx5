/* Lever expr_commutative_rtl_order (before): plain int local e as the left operand -> addu $3,$3,$6
   (the sign-extended byte stays first). */
struct S { int pad; unsigned short e; unsigned char *p; };
void lever_addu(struct S *s)
{
    unsigned char *p = s->p;
    int e = s->e;
    s->e = (-(p[3] + (e + (signed char)p[1])) & 0xF) + e;
}
