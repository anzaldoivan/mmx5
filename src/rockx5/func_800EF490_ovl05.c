#include "types.h"

extern void func_800171E8(Ent6B44*, s32);
extern u8 D_800F4FF4_ovl05[];
extern u8 D_800F4FEC_ovl05[];
extern u8 D_800F4FF0_ovl05[];
extern u8 D_80074E40[];

void func_800EF490_ovl05(Ent6B44* e) {
    Ent6B44* p = e->unk7C;

    e->unk3 = 1;
    e->unk68 = (s32)D_800F4FF4_ovl05;
    e->unk54 = (s32)D_800F4FEC_ovl05;
    e->unk4++;
    e->unk28 = 0;
    e->unk2C = 0;
    e->unk67 = 0;
    e->unk16 = 1;
    e->unk50 = (s32)D_800F4FF0_ovl05;
    e->unk58 = (s32)D_80074E40;
    e->unk40 = p->unk40;
    e->unk42 = p->unk42 & 0x7FFF;
    e->unk30 = p->unk30;
    e->unk3C = p->unk3C;
    e->unk15 = p->unk15;
    e->unk14 = p->unk14;
    e->unk5C = 1;
    e->unk60 = 3;
    e->unk20 <<= 1;
    e->unk24 <<= 1;
    func_800171E8(e, 0xF);
}
