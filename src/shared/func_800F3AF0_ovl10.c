/* Shared body (DK-5), from the banked draft of func_800F3AF0_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj, s32 state);
extern s32 D_8009A0A8;
extern s8 D_800D1C0C;

void DEDUP_NAME(u8* obj) {
    s32 hi;
    s32 lo;
    s32 d;
    s32 v;

    if (D_800D1C0C != 0xC) {
        hi = 0x20000000;
        lo = 0x1F800000;
    } else {
        hi = 0x0B000000;
        lo = 0x0A800000;
    }
    if (D_8009A0A8 < hi) {
        d = *(s32*)(obj + 8) + 0xFF800000;
        if (hi - d >= 0) {
            v = (hi - d + 0x10000) / 60;
        } else {
            v = (d - hi + 0x10000) / 60;
        }
        *(s32*)(obj + 0x20) = v;
        if (hi + 0x800000 < *(s32*)(obj + 8)) {
            *(s32*)(obj + 0x20) = -*(s32*)(obj + 0x20);
            obj[0x15] = 0;
        } else {
            obj[0x15] = 0x40;
        }
    } else {
        d = *(s32*)(obj + 8);
        if (lo - d >= 0) {
            d = -((lo - d + 0x10000) / 60);
        } else {
            d = -((d - lo + 0x10000) / 60);
        }
        *(s32*)(obj + 0x20) = d;
        if (*(s32*)(obj + 8) < lo) {
            *(s32*)(obj + 0x20) = -*(s32*)(obj + 0x20);
            obj[0x15] = 0x40;
        } else {
            obj[0x15] = 0;
        }
    }
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0x64000;
    *(s32*)(obj + 0x2C) = 0x3800;
    DEDUP_CALLEE(obj, 2);
    obj[6] = 1;
}
