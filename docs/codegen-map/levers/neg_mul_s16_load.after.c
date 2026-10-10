/* Lever neg_mul_s16_load (after): `*= -1` on the same field keeps the sign-extending lh before negu. */
typedef struct { short pad; short x; } S;
void lever_negmul(S *p) { p->x *= -1; }
