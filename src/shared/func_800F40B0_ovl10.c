/* Shared body (DK-5), from the banked draft of func_800F40B0_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern u8* func_8002D1A4();
extern s8 D_8009A0A2;

void DEDUP_NAME(u8* obj) {
    u8* p;
    u8 dir;

    if (obj[0x8A] == 2) {
        if (*(s8*)(obj + 2) != 0) {
            if (*(s8*)(*(u8**)(obj + 0x80) + 6) < 5) {
                if (D_8009A0A2 != 0) {
                    *(s16*)(obj + 0x7E) = 0x3D;
                    return;
                }
                *(s16*)(obj + 0x7E) = 1;
                return;
            }
        } else if (*(s8*)(obj + 0x98) != 0) {
            if (*(s8*)(*(u8**)(obj + 0x80) + 6) < 5) {
                return;
            }
        }
    }
    if (*(s16*)(obj + 0x7E) != 0) {
        *(s16*)(obj + 0x7E) = *(s16*)(obj + 0x7E) - 1;
        return;
    }
    func_80017248(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        obj[7] = 0;
        p = func_8002D1A4();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x27;
            p[4] = 0;
            *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
            *(u16*)(p + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
            *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
            p[0x14] = obj[0x14];
            dir = obj[0x15];
            p[0x15] = dir;
            if (dir != 0) {
                *(s32*)(p + 8) = *(s32*)(obj + 8) + 0x4EEE90;
            } else {
                *(s32*)(p + 8) = *(s32*)(obj + 8) - 0x4EEE90;
            }
            *(s32*)(p + 0xC) = *(s32*)(obj + 0xC) - 0x90000;
            *(u8**)(p + 0x7C) = obj;
            if (obj[0x90] != 0) {
                *(s16*)(p + 0xE) += 0xB;
                if (p[0x15] != 0) {
                    *(s16*)(p + 0xA) -= 8;
                } else {
                    *(s16*)(p + 0xA) += 8;
                }
            }
        }
        obj[6] = 6;
    }
}
