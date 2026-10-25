/* Shared body (DK-5), from the banked draft of func_800F0DAC_ovl02 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

#define SCR D_1F80004C.scr4c
#define SCRB D_1F80004C.bytes

extern void func_800171E8(Obj0DAC*, s32);
extern void func_800F2B54_ovl02(Obj0DAC*);
extern u8 D_80074EE0[];
extern X4_Obj D_8009A0A0;
extern s32 D_800F46E8_ovl02;
extern s32 D_800F462C_ovl02;
extern s32 D_800F4630_ovl02;
extern u8 D_8009A0B4;
extern s32 D_800F4638_ovl02;
extern s32 D_800F4634_ovl02;
extern Unk800770CC D_800F463C_ovl02;
extern u8 D_80074E40[];

void DEDUP_NAME(Obj0DAC* e) {
    if (e->unk2 < 0x10) {
        e->unk5C = 0x2D;
        e->unk60 = 5;
        e->unk58 = D_80074EE0;
        e->unk61 = 0;
        e->unk14 = D_8009A0A0.bg_offset;
        e->unk67 = 0;
        e->unk68 = 0;
        e->unk30 = &D_800F46E8_ovl02;
        e->unk16 = 6;
        e->unk50 = &D_800F462C_ovl02;
        e->unk18 = e->x.val;
        e->unk1C = e->y.val;
        func_800171E8(e, 0);
        e->unk70 = 0;
        e->unk68 = &D_800F4630_ovl02;
        if (D_8009A0A0.x_pos.val <= e->x.val) {
            e->unk15 = 0;
        } else {
            e->unk15 = 0x40;
        }
        SCRB[0x80] = 1;
        SCRB[0x81] = 8;
        SCRB[0x82] = 0;
        e->unk67 = 1;
        e->f20 = 0;
        e->f24 = 0;
        e->f28 = 0;
        e->f2C = 0x4200;
        e->unk5 = 5;
        e->unk4 = 1;
        e->unk6 = 0;
    } else {
        e->unk3 = 1;
        e->unk5C = 1;
        e->unk60 = 4;
        e->unk14 = D_8009A0B4;
        func_800171E8(e, 5);
        e->unk50 = &D_800F4638_ovl02;
        e->unk54 = &D_800F4634_ovl02;
        e->unk68 = &SCR->box;
        SCR->box = D_800F463C_ovl02;
        SCR->flags83 = 0;
        SCR->cnt88 = 3;
        e->unk58 = D_80074E40;
        e->unk4 = 5;
        e->unk5 = 2;
        e->unk70 = 0;
        e->unk16 = 4;
        e->f20 = 0;
        e->f28 = 0;
        e->f24 = 0;
        e->f2C = 0;
        if (e->unk2 == 0x10) {
            if (e->unk15 == 0) {
                e->x.u.hi -= 12;
            } else {
                e->x.u.hi += 8;
            }
            e->unk5 = 11;
            e->f24 = 0x20000;
            e->y.u.hi -= 16;
        } else {
            if (e->unk15 == 0) {
                e->x.u.hi -= 8;
            } else {
                e->x.u.hi += 8;
            }
            e->unk5 = 2;
            e->f24 = 0xFFFE0000;
            e->y.u.hi += 16;
        }
        func_800F2B54_ovl02(e);
        e->unk4 = 5;
        e->unk6 = 0;
    }
}
