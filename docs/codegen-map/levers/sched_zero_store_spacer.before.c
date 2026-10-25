/* Lever sched_zero_store_spacer (before): the zero store unk67 sits after the tied hi/lo pair of D_tab. local-alloc's
   INSN_SCHEDULING fake lifetime makes hi(D_g) conflict with hi(D_tab), which takes $2 first; hi(D_g) lands in $3. */
struct E { char p0[0x14]; unsigned char unk14; char p1[0x1B]; void *unk30; char p2[0x28]; unsigned char unk5C; char p3[3]; unsigned char unk60, unk61; char p4[5]; unsigned char unk67; };
extern unsigned char D_g;
extern unsigned char D_tab[];
void lever_spacer(struct E *e)
{
    e->unk5C = 0x20;
    e->unk60 = 0xA;
    e->unk61 = 0;
    e->unk14 = D_g;
    e->unk30 = D_tab;
    e->unk67 = 0;
}
