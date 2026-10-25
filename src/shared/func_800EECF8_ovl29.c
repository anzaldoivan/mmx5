/* Shared body (DK-5), from the banked draft of func_800EECF8_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(ObjEECF8*, s32);
extern X4_Obj D_8009A0A0;
extern u8 D_800F9104_ovl29[];
extern Unk800770CC D_800F8FB4_ovl29[];
extern u8 D_800F8FBC_ovl29[];
extern u8 D_800F8FB8_ovl29[];
extern u8 D_80074EE0[];
extern u8 D_800750C0[];

void DEDUP_NAME(ObjEECF8* e) {
    e->unk7C = 0;
    e->unk5C = 6;
    e->unk61 = 0;
    e->unk14 = D_8009A0A0.bg_offset;
    e->unk18 = e->x.val;
    e->unk1C = e->y.val;
    if (D_8009A0A0.x_pos.val < e->x.val) {
        e->unk15 = 0;
    } else {
        e->unk15 = 0x40;
    }
    e->unk30 = D_800F9104_ovl29;
    e->unk16 = 4;
    e->unk68 = D_800F8FB4_ovl29;
    e->unk54 = D_800F8FBC_ovl29;
    e->unk50 = D_800F8FB8_ovl29;
    e->unk67 = 0;
    switch (e->unk2) {
    case 0:
        e->unk58 = D_800750C0;
        DEDUP_CALLEE(e, 1);
        e->unk60 = 3;
        e->unk80 = 0;
        e->unk88 = 0;
        e->unk8C = 0x78;
        e->unk5 = 2;
        break;
    case 1:
        e->unk58 = D_80074EE0;
        e->unk80 = 1;
        e->unk60 = 4;
        e->unk88 = 0;
        e->unk8C = 0x78;
        e->unk5 = 5;
        break;
    default:
        e->unk58 = D_80074EE0;
        e->unk60 = 4;
        e->unk80 = 1;
        e->unk88 = 0;
        e->unk8C = 0x78;
        DEDUP_CALLEE(e, 5);
        e->unk5 = 8;
        break;
    }
    e->unk20 = 0;
    e->unk24 = 0;
    e->unk28 = 0;
    e->unk2C = 0;
    e->unk4 = 1;
    e->unk6 = 0;
}
