/* Shared body (DK-5), from the banked draft of func_800F4E10_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern s8 D_800D1C00[];
extern s16 D_8009A1F8[];
extern void DEDUP_CALLEE(s32, s32);

void DEDUP_NAME(Obj* obj) {
    if (D_800D1C00[0xF] != 0) {
        return;
    }
    if (obj->timer == 0x122) {
        if (D_800D1C00[0xC] != 0xC) {
            D_8009A1F8[0x13] = 0x1F70;
            D_8009A1F8[0x12] = 0x1F70;
        } else {
            D_8009A1F8[0x13] = 0xA70;
            D_8009A1F8[0x12] = 0xA70;
        }
    }
    if (D_800D1C00[0xC] != 0xC && obj->timer == 0x104) {
        DEDUP_CALLEE(0x14, 0x40);
    }
    if (--obj->timer == 0) {
        obj->timer = 0xF0;
        obj->step = 2;
    }
}
