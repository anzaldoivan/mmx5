/* Shared body (DK-5), from the banked draft of func_800F8E6C_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern u8 D_800D1CA2;

void DEDUP_NAME(u8* obj) {
    if (*(s8*)(obj + 0x45) == 1) {
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        func_800171E8(obj, 0xE);
        if (obj[0x96] == 0) {
            if (obj[0x15] != 0) {
                if (obj[0x70] & 2) {
                    *(s32*)(obj + 0x20) = 0x1E000;
                } else {
                    *(s32*)(obj + 0x20) = 0x1B000;
                }
            } else if (obj[0x70] & 1) {
                *(s32*)(obj + 0x20) = -0x1E000;
            } else {
                *(s32*)(obj + 0x20) = -0x1B000;
            }
            *(s32*)(obj + 0x2C) = 0xE00;
            *(s32*)(obj + 0x24) = 0x2E800;
        } else if (*(s8*)(obj + 0x92) == 3) {
            if (obj[0x15] != 0) {
                *(s32*)(obj + 0x20) = -0x1B000;
            } else {
                *(s32*)(obj + 0x20) = 0x1B000;
            }
            *(s32*)(obj + 0x2C) = 0xE00;
            *(s32*)(obj + 0x24) = 0x2E800;
        }
        if (*(s8*)(obj + 0x92) == 2 || *(s8*)(obj + 0x92) == 4) {
            *(s32*)(obj + 0x20) /= 2;
        }
        if (*(s8*)(obj + 0x5C) < (s8)((s8)D_800D1CA2 / 3)) {
            *(s32*)(obj + 0x2C) = 0x145D;
            *(s32*)(obj + 0x24) = 0x38000;
            *(s32*)(obj + 0x20) = *(s32*)(obj + 0x20) * 120 / 100;
        }
        obj[6] = 1;
    }
    if (obj[0x96] != 0 && *(s8*)(obj + 0x92) != 3) {
        func_800171E8(obj, 0);
        obj[5] = 3;
        obj[6] = 0;
        *(s16*)(obj + 0x7C) = 60;
    } else {
        func_80017248(obj);
    }
}
