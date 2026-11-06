#include "types.h"

extern void func_80016490(s32, s32, void*);
extern u8* func_8002D1A4();
extern u8 D_800FAAB4_ovl09[];

void func_800F136C_ovl09(u8* a0) {
    u8* o;
    s32 t;

    t = *(u16*)(a0 + 0x7E) - 1;
    *(u16*)(a0 + 0x7E) = t;
    if ((t << 16) == 0) {
        if (*(s8*)(a0 + 3) != 0) {
            func_80016490(5, 0x18, a0);
        }
        o = func_8002D1A4();
        if (o != 0) {
            o[0] = 0x41;
            o[1] = 0x12;
            o[2] = 0;
            *(u8**)(o + 0x7C) = a0;
            *(u16*)(o + 0x42) = *(u16*)(a0 + 0x42) & 0x7FFF;
            *(u8**)(o + 0x30) = D_800FAAB4_ovl09;
            *(s32*)(o + 0x3C) = *(s32*)(a0 + 0x3C);
            *(u16*)(o + 0x40) = *(u16*)(a0 + 0x40);
            o[0x15] = a0[0x15];
            o[0x14] = a0[0x14];
            *(s32*)(o + 0x8) = *(s32*)(a0 + 0x8);
            *(s32*)(o + 0xC) = *(s32*)(a0 + 0xC);
            o[0x16] = 4;
        }
        a0[5] = 2;
        a0[6] = 0;
    }
}
