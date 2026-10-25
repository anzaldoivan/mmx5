/* Shared body (DK-5), from the banked draft of func_800F55F8_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern signed char D_800D1C0C;
extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    s32 lim = 0xB0;

    if (D_800D1C0C != 12) {
        lim = 0xA0;
    }
    func_80017248(obj);
    if (*(s16*)(obj + 0xE) < lim) {
        *(s16*)(obj + 0xE) += 1;
    } else if (lim < *(s16*)(obj + 0xE)) {
        *(s16*)(obj + 0xE) -= 1;
    } else {
        if (*(signed char*)(obj + 0x46) == 0) {
            func_800171E8(obj, 3);
        }
        *(s32*)(obj + 0x98) = 0;
        *(s16*)(obj + 0x7C) = 30;
        obj[6]++;
    }
}
