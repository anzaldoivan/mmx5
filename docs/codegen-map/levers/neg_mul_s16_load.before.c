/* Lever neg_mul_s16_load (before): unary negate of an s16 field; only the low half is stored, so the load is lhu. */
typedef struct { short pad; short x; } S;
void lever_negmul(S *p) { p->x = -p->x; }
