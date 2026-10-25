/* Shared body (DK-5), from the banked draft of func_800FAC80_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_800D1C00[];
extern void func_80024548(s32);
extern void func_800171E8(u8*, s32);

void DEDUP_NAME(u8* obj) {
    if (**(signed char**)(obj + 0x8C) == 0) {
        D_800D1C00[0x24] = 1;
        D_800D1C00[0x25] = 0;
        D_800D1C00[0xA2] = 0x36;
        *(u8**)(D_800D1C00 + 0x20) = obj;
        if ((signed char)D_800D1C00[0xC] == 0xC) {
            func_80024548(-1);
        } else {
            func_80024548(1);
        }
        *(s32*)(obj + 0x2C) = 0x8000;
        func_800171E8(obj, 0x11);
        obj[6] = 3;
    }
}
