#include "types.h"

extern u8* func_8002D078();
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_8009A0A0[];

void func_8004F730(u8* p) {
    u8* o;

    if (*(s8*)(p + 0x45) != 0) {
        if (*(s8*)(p + 2) != 0) {
            o = func_8002D078();
            if (o != 0) {
                o[0] = 0x21;
                o[1] = p[2];
                o[2] = 0;
                *(s32*)(o + 0x8) = *(s32*)(p + 0x8);
                *(s32*)(o + 0xC) = *(s32*)(p + 0xC);
                o[0x15] = p[0x15];
                *(s32*)(o + 0x3C) = *(s32*)(p + 0x3C);
                *(s32*)(o + 0x30) = *(s32*)(p + 0x30);
                *(u16*)(o + 0x40) = *(u16*)(p + 0x40);
                *(u16*)(o + 0x42) = *(u16*)(p + 0x42);
                o[0x16] = p[0x16];
                D_8009A0A0[0x98]++;
            }
        }
        p[5]++;
    }
    func_8002D9EC(p, 0x40, 0x20);
}
