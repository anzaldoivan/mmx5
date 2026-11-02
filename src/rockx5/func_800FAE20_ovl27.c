#include "types.h"

extern void func_80016490(s32, s32, void*);
extern u8* func_8002D1A4();
extern s32 rcos(s32);
extern s32 rsin(s32);

void func_800FAE20_ovl27(u8* arg0, s32 arg1) {
    u8* o;
    s32 t;

    o = func_8002D1A4();
    if (o != 0) {
        o[0] = 0x41;
        o[1] = 0x21;
        *(u8**)(o + 0x7C) = arg0;
        o[2] = 0;
        *(u16*)(o + 0xA) = *(u16*)(arg0 + 0xA);
        *(s16*)(o + 0x8) = 0;
        *(u16*)(o + 0xE) = *(u16*)(arg0 + 0xE);
        *(s16*)(o + 0xC) = 0;
        *(u16*)(o + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
        *(s32*)(o + 0x30) = *(s32*)(arg0 + 0x30);
        *(s32*)(o + 0x3C) = *(s32*)(arg0 + 0x3C);
        *(u16*)(o + 0x40) = *(u16*)(arg0 + 0x40);
        o[0x14] = arg0[0x14];
        *(s32*)(o + 0x28) = 0;
        *(s32*)(o + 0x2C) = 0;
        *(s32*)(o + 0x20) = rcos(arg1) << 4;
        *(s32*)(o + 0x24) = rsin(arg1) << 4;
        t = *(s32*)(o + 0x20);
        if (t != 0) {
            *(s32*)(o + 0x20) = t << 3;
        } else {
            *(s32*)(o + 0x20) = 0;
        }
        if (*(s32*)(o + 0x24) != 0) {
            *(s32*)(o + 0x24) = *(s32*)(o + 0x24) << 3;
        } else {
            *(s32*)(o + 0x24) = 0;
        }
        func_80016490(2, 0x65, arg0);
    }
}
