#include "types.h"

extern u8* func_8002D27C(void);
extern u8 D_8009A0B4;
extern u8 D_800FB278_ovl09[];

void func_800F7734_ovl09(u8* e) {
    u8* o;

    if (++*(u16*)(e + 0x84) == 0x60) {
        o = func_8002D27C();
        if (o != 0) {
            o[0] = 0x41;
            o[1] = 0x25;
            o[2] = 1;
            o[0x14] = D_8009A0B4;
            o[0x16] = 1;
            o[0x15] = e[0x15];
            *(u16*)(o + 0x40) = *(u16*)(e + 0x40);
            *(u16*)(o + 0x42) = *(u16*)(e + 0x42);
            *(s32*)(o + 0x3C) = *(s32*)(e + 0x3C);
            *(u8**)(o + 0x30) = D_800FB278_ovl09;
            *(s32*)(o + 0x8) = *(s32*)(e + 0x8);
            *(s32*)(o + 0xC) = *(s32*)(e + 0xC);
            o[0x54] = 0;
            *(u8**)(e + 0x7C) = o;
            *(u16*)(e + 0x84) = 0;
            e[6]++;
        }
    }
}
