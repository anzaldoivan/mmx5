/* Lever regalloc_const_store_interleave (after): a $0 store interleaved between constant stores -> the
   freed reg is reusable, constants cycle through $2/$3 only. */
struct S { unsigned char a, b, c, d, z, y; };
void lever_lisb(struct S *o)
{
    o->a = 1;
    o->b = 2;
    o->z = 0;
    o->c = 0x41;
    o->y = 0;
    o->d = 1;
}
