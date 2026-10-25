/* Shared body (DK-5), from the banked draft of func_800F6A64_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(Ent6B44*, s32);
extern u8 D_800FB0B8_ovl09[];
extern u8 D_80074DA0[];

void DEDUP_NAME(Ent6B44* e) {
    Ent6B44* p;

    p = e->unk7C;
    e->unk40 = p->unk40;
    e->unk42 = p->unk42 & 0x7FFF;
    e->unk30 = D_800FB0B8_ovl09;
    e->unk3C = p->unk3C;
    e->unk14 = 0;
    e->unk16 = 1;
    e->unk15 = p->unk15;
    e->unk67 = 0;
    e->unk3 = 0;
    e->unk68 = 0;
    e->unk50 = 0;
    e->unk54 = 0;
    e->unk58 = (s32)D_80074DA0;
    e->unk20 = 0;
    e->unk24 = 0;
    e->unk28 = 0;
    e->unk2C = 0;
    e->unk5C = 1;
    e->unk60 = 7;
    DEDUP_CALLEE(e, 4);
    e->pad6[0] = 0;
    e->unk5 = 0;
    e->unk4++;
}
