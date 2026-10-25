/* Shared body (DK-5), from the banked draft of func_800EEF84_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 func_80030AE4(ObjEECF8*, s16, s16);
extern void func_800171E8(ObjEECF8*, s32);
extern s32 D_8009A0A8;

void DEDUP_NAME(ObjEECF8* e) {
    s16 x;
    s32 dx;

    if (e->unk5 != 2) {
        return;
    }
    if (e->unk7C != 0) {
        e->unk7C--;
        return;
    }
    if (e->unk15) {
        x = e->x.i.hi + e->unk68->a + 0x10;
    } else {
        x = e->x.i.hi - e->unk68->a - 0x10;
    }
    if (!func_80030AE4(e, x, e->unk68->d + (e->y.i.hi + e->unk68->b))) {
        e->unk8C = 0x78;
        e->unk5 = 3;
        e->unk6 = 0;
        func_800171E8(e, 2);
    }
    if (e->unk88 == 0) {
        if (e->unk15) {
            if (e->unk70 & 1) {
                e->unk5 = 3;
                e->unk6 = 0;
                e->unk8C = 0x78;
                func_800171E8(e, 2);
            }
        } else {
            if (e->unk70 & 2) {
                e->unk5 = 3;
                e->unk6 = 0;
                e->unk8C = 0x78;
                func_800171E8(e, 2);
            }
        }
    } else {
        dx = e->x.val - D_8009A0A8;
        if (e->unk15) {
            if (dx > 0 || (e->unk70 & 1)) {
                e->unk5 = 3;
                e->unk6 = 0;
                e->unk88 = 0;
                e->unk8C = 0x3C;
                func_800171E8(e, 2);
            }
        } else {
            if (dx < 0 || (e->unk70 & 2)) {
                e->unk5 = 3;
                e->unk6 = 0;
                e->unk88 = 0;
                e->unk8C = 0x3C;
                func_800171E8(e, 2);
            }
        }
    }
}
