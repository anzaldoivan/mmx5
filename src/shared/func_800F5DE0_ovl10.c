#include "types.h"
#include "mmx5/globals.h"

void func_800F5DE0_ovl10(u8* obj) {
    if (obj[0x8A] == 2 && *(signed char*)(obj + 0x87) != 0) {
        obj[0x87]--;
        return;
    }
    animate_object(obj);
    if (*(signed char*)(obj + 0x45) == 1 && *(signed char*)(obj + 0x87) == 0) {
        obj[0x6] = 3;
    }
}

extern s8 D_8009A0A2;

void func_800F5E54_ovl10(u8* arg0) {
    u8* p;
    u8 t;

    p = func_8002D1A4();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x27;
        p[4] = 0;
        *(u16*)(p + 0x40) = *(u16*)(arg0 + 0x40);
        *(u16*)(p + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
        *(s32*)(p + 0x30) = *(s32*)(arg0 + 0x30);
        *(s32*)(p + 0x3C) = *(s32*)(arg0 + 0x3C);
        p[0x14] = arg0[0x14];
        t = arg0[0x15];
        p[0x15] = t;
        if (t != 0) {
            *(s32*)(p + 0x8) = *(s32*)(arg0 + 0x8) + 0x4EEE90;
        } else {
            *(s32*)(p + 0x8) = *(s32*)(arg0 + 0x8) + 0xFFB11170;
        }
        *(s32*)(p + 0xC) = *(s32*)(arg0 + 0xC) + 0xFFF70000;
        *(u8**)(p + 0x7C) = arg0;
        if (arg0[0x90] != 0) {
            *(u16*)(p + 0xE) += 0xB;
            if (p[0x15] != 0) {
                *(u16*)(p + 0xA) -= 8;
            } else {
                *(u16*)(p + 0xA) += 8;
            }
        }
    }
    arg0[6] = 4;
    arg0[0x87] = 0;
    *(s16*)(arg0 + 0x7E) = 0;
    if (D_8009A0A2 != 0) {
        *(s16*)(arg0 + 0x7E) = 0x3C;
    }
}
