/* Shared body (DK-5), from the banked draft of func_800EF094_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(ObjEF094*, s32);
extern u8 D_8009A0B4;
extern u8 D_800750C0[];
extern u8 D_800F9624_ovl03[];
extern u8 D_800F959C_ovl03[];
extern u8 D_800F95A4_ovl03[];
extern u16 D_800D1C0C;

void DEDUP_NAME(ObjEF094* e) {
    e->unk0 = 0x41;
    e->unk5C = 3;
    e->unk60 = 3;
    e->unk61 = 0;
    e->unk14 = D_8009A0B4;
    e->unk58 = D_800750C0;
    e->unk20 = 0;
    e->unk30 = D_800F9624_ovl03;
    e->unk16 = 6;
    e->unk54 = D_800F959C_ovl03;
    e->unk50 = D_800F95A4_ovl03;
    e->unk24 = 0;
    e->unk28 = 0;
    e->unk2C = 0;
    e->unk67 = 0;
    e->unk68 = 0;
    e->unk80 = 0;
    e->unk84 = 0;
    e->unk88 = 0;
    e->unk8C = 0;
    e->unk90 = 0;
    e->unk94 = 0;
    e->unk18 = e->unk8;
    e->unk1C = e->unkC;
    e->unk4++;
    switch (e->unk2) {
    case 0:
        DEDUP_CALLEE(e, 0);
        e->unk5 = 2;
        break;
    case 1:
        DEDUP_CALLEE(e, 3);
        e->unk5 = 5;
        e->unk88 = 1;
        break;
    case 4:
        DEDUP_CALLEE(e, 3);
        e->unk5 = 7;
        e->unk88 = 1;
        break;
    default:
        DEDUP_CALLEE(e, 3);
        e->unk5 = 6;
        e->unk88 = 1;
        break;
    }
    e->unk6 = 0;
    if (D_800D1C0C == 2) {
        e->unk7 = e->unk5;
        e->unk5 = 9;
        e->unk54 = 0;
        e->unk50 = 0;
    }
}
