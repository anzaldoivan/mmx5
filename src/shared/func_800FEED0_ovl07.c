/* Shared body (DK-5), from the banked draft of func_800FEED0_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8001296C(s32);
extern void func_800171E8(u8* obj, s32 state);
extern u32 func_8002DF78(void);
extern signed char D_800D1C0C;

void DEDUP_NAME(u8* obj) {
    s32 d;

    obj[0x16] = 4;
    switch ((s8)obj[2]) {
    case 0:
        func_8001296C(2);
        func_800171E8(obj, 0x17);
        obj[0x15] = 0;
        d = (u8)(func_8002DF78() % 48) + 0xFFE8;
        *(u16*)(obj + 0xA) += d;
        if (D_800D1C0C != 0xC) {
            *(s16*)(obj + 0xE) = 0x480;
        } else {
            *(s16*)(obj + 0xE) = 0x40;
        }
        obj[4] = 3;
        break;
    case 1:
        func_800171E8(obj, 1);
        obj[4] = 1;
        break;
    case 2:
        func_800171E8(obj, 3);
        obj[4] = 1;
        break;
    }
    obj[6] = 0;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
}
