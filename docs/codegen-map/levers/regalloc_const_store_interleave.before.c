/* Lever regalloc_const_store_interleave (before): back-to-back constant byte stores -> local-alloc's
   INSN_SCHEDULING lifetime extension keeps each li off the reg the previous one freed: $5, $2, $3. */
struct S { unsigned char a, b, c, d, z, y; };
void lever_lisb(struct S *o)
{
    o->a = 1;
    o->b = 2;
    o->c = 0x41;
    o->d = 1;
    o->z = 0;
    o->y = 0;
}
