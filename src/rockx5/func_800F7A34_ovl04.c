#include "types.h"

extern Obj8002CD14* func_8002CD14(Obj8002CD14* p, s32 backward);
extern u8 D_80101D58_ovl04[];

void func_800F7A34_ovl04(u8* o) {
    u8* c;
    s8 n;

    n = o[2];
    *(s32*)(o + 0x68) = 0;
    if (n != 0x64) {
        if (n == 0x66) {
            *(u8**)(o + 0x68) = D_80101D58_ovl04;
        }
        if (*(s16*)(o + 0xA) - *(s16*)(o + 0x80) < 0x20) {
            return;
        }
        c = (u8*)func_8002CD14((Obj8002CD14*)o, 0);
        if (c != 0) {
            c[0] = 0x41;
            c[1] = 7;
            *(u16*)(c + 0x40) = *(u16*)(o + 0x40);
            *(s32*)(c + 0x30) = *(s32*)(o + 0x30);
            *(s32*)(c + 0x3C) = *(s32*)(o + 0x3C);
            *(u16*)(c + 0x42) = *(u16*)(o + 0x42);
            c[2] = o[2] - 1;
            *(u16*)(c + 0xA) = *(u16*)(o + 0xA) - 0x20;
            *(u16*)(c + 0xE) = *(u16*)(o + 0xE);
            *(s32*)(c + 0x20) = *(s32*)(o + 0x20);
            c[0x66] = 1;
            *(s32*)(c + 0x7C) = *(s32*)(o + 0x7C);
            *(u16*)(c + 0x80) = *(u16*)(o + 0x80);
        }
    }
    o[6] = 2;
}
