#include "types.h"

extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern u8 D_8009A0A0[];
extern void* D_800FB7CC_ovl10[];

void func_800F21D4_ovl10(u8* o) {
    u8* p;

    if (func_8002D938(o, 0x20, 0x20) == 0) {
        func_8002D9EC(o, 0x10, 0x10);
        if (*(s8*)(o + 5) != 3) {
            o[3] = 0;
        }
    } else {
        o[4] = 3;
    }
    if (func_80031DD0(o) < 0) {
        if (*(s8*)(o + 5) == 3) {
            D_8009A0A0[0xCA] = 0;
        }
        o[4] = 4;
        *(u16*)(o + 0x42) &= 0x7FFF;
    }
    if (D_8009A0A0[0xF7] == 0) {
        o[0x62] = 3;
        *(s32*)(o + 0x18) = *(s32*)(o + 8);
        *(s32*)(o + 0x1C) = *(s32*)(o + 0xC);
        ((void (*)(u8*))D_800FB7CC_ovl10[*(s8*)(o + 5)])(o);
    } else {
        o[0x62] = 0;
        func_800317B8(o);
    }
    p = *(u8**)(o + 0x7C);
    if (*(s8*)(p + 4) != 1) {
        if (*(s8*)(o + 5) == 3) {
            D_8009A0A0[0xCA] = 0;
        }
        o[4] = 3;
        return;
    }
    if ((u32)(o[4] - 3) < 2) {
        p[0x80] = 0;
    }
}
