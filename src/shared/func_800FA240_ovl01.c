/* Shared body (DK-5), from the banked draft of func_800FA240_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern signed char D_800D1C0C;
extern u8 D_800FD5A8_ovl01[];
extern u8 D_800FD5AC_ovl01[];
extern void DEDUP_CALLEE(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    obj[0x94] = 0;
    DEDUP_CALLEE(obj, 0xE);
    *(u8**)(obj + 0x50) = D_800FD5A8_ovl01;
    *(u8**)(obj + 0x54) = D_800FD5AC_ovl01;
    obj[6] = 1;
    *(s16*)(obj + 0x7C) = 0;
    *(s32*)(obj + 0x68) = 0;
    if (D_800D1C0C != 12) {
        *(s16*)(obj + 0xA) = 0x25E0;
        *(s16*)(obj + 0xE) = 0xB0;
    } else {
        *(s16*)(obj + 0xA) = 0x2E0;
        *(s16*)(obj + 0xE) = -0x30;
    }
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0x4000;
}
