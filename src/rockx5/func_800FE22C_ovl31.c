#include "types.h"

extern u8 D_80074EE0[];

// from rockx5 800FE22C (byte twin of 800F7240_ovl03): child init, copies pose from parent (unk7C) and picks a timer by unk2
void func_800FE22C_ovl31(Ent7240* e) {
    Ent7240* p = e->unk7C;

    e->unk40 = p->unk40;
    e->unk42 = p->unk42 & 0x7FFF;
    e->unk30 = p->unk30;
    e->unk3C = p->unk3C;
    e->unk16 = 1;
    e->unk14 = 0;
    e->unk15 = p->unk15;
    e->unk67 = 0;
    e->unk3 = 0;
    e->unk68 = 0;
    e->unk50 = 0;
    e->unk54 = 0;
    e->unk58 = D_80074EE0;
    if (e->unk15 == 0) {
        e->unkA = p->unkA - 5;
    } else {
        e->unkA = p->unkA + 5;
    }
    e->unkE = ((Ent7240*)e->unk7C)->unkE - 0x14;
    e->unk60 = 7;
    e->unk20 = 0;
    e->unk24 = 0;
    e->unk28 = 0;
    e->unk2C = 0;
    e->unk5C = 1;
    switch (e->unk2) {
    case 0:
        e->unk84 = 0x43;
        break;
    case 1:
        e->unk84 = 0x4B;
        break;
    case 2:
        e->unk84 = 0x53;
        break;
    case 3:
        e->unk84 = 0x14;
        break;
    case 4:
        e->unk84 = 0x1C;
        break;
    case 5:
        e->unk84 = 0x24;
        break;
    }
    e->unk5 = 0;
    e->unk4++;
}
