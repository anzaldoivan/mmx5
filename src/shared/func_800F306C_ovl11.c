/* Shared body (DK-5), from the banked draft of func_800F306C_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(Obj306C* obj, s32 state);
extern u8 D_800F9B84_ovl11[];
extern u8 D_800F9B88_ovl11[];
extern s8 D_800F9B8C_ovl11[][2];

void DEDUP_NAME(Obj306C* obj) {
    s32 v;
    s16 a;
    s32 r;
    u8 d;

    obj->unk3 = 1;
    obj->unk4++;
    if ((s8)obj->unk2 & 0x80) {
        obj->unk24 = 0;
        if ((obj->unk2 & 0xF) == 1) {
            v = 0xFFFD0000;
            if (obj->unk15 != 0) {
                v = 0x30000;
            }
            obj->unk20 = v;
        } else {
            v = 0xFFFE8000;
            if (obj->unk15 != 0) {
                v = 0x30000;
            }
            obj->unk20 = v;
        }
        if ((obj->unk2 & 0xF) == 0) {
            obj->unk24 = 0x18000;
        }
        if ((obj->unk2 & 0xF) == 2) {
            obj->unk24 = 0xFFFE8000;
        }
        obj->unk28 = 0;
        obj->unk2C = 0;
        DEDUP_CALLEE(obj, 0x10);
        obj->unk60 = 2;
    } else {
        v = 0xFFFD0000;
        if (obj->unk15 != 0) {
            v = 0x30000;
        }
        obj->unk20 = v;
        obj->unk28 = 0;
        obj->unk24 = 0x18000;
        obj->unk2C = 0x4000;
        DEDUP_CALLEE(obj, 0x16);
        obj->unk60 = 5;
    }
    a = obj->unkA;
    if (obj->unk15 != 0) {
        r = a + D_800F9B8C_ovl11[obj->unk2 & 0xF][0];
    } else {
        r = a - D_800F9B8C_ovl11[obj->unk2 & 0xF][0];
    }
    obj->unkA = r;
    d = ((Tbl9B8C*)D_800F9B8C_ovl11)->f1[(obj->unk2 & 0xF) * 2];
    obj->unk67 = 0;
    obj->unk16 = 6;
    obj->unk68 = D_800F9B88_ovl11;
    obj->unk54 = D_800F9B84_ovl11;
    obj->unk50 = D_800F9B84_ovl11;
    obj->unkE += (s8)d;
}
