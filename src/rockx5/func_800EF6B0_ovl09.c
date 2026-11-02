#include "types.h"

extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FD24(u8* a0);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_80054440(u8* a0, s32 a1);
extern u8* func_8002D1A4();
extern s32 func_800317B8(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_8009A197;
extern u8 D_800FA83C_ovl09[];
extern void* D_800FA854_ovl09[];

void func_800EF6B0_ovl09(u8* o) {
    s32 dir;

    if (func_80031DD0(o) < 0) {
        o[5] = 0;
        o[4]++;
        *(u16*)(o + 0x42) &= 0x7FFF;
        func_8004FD24(o);
        func_8004D4F4(3, D_800FA83C_ovl09, o);
        func_80054440(o, 0x12);
        return;
    }
    if (D_8009A197 == 0) {
        u8* c;

        ((void (*)(u8*))D_800FA854_ovl09[*(s8*)(o + 5)])(o);
        c = func_8002D1A4();
        if (c != 0 && *(s8*)(o + 7) == 0) {
            o[7] = 1;
            c[0] = 0x41;
            c[1] = 0x16;
            *(u16*)(c + 0x40) = *(u16*)(o + 0x40);
            *(u16*)(c + 0x42) = *(u16*)(o + 0x42) & 0x7FFF;
            *(s32*)(c + 0x3C) = *(s32*)(o + 0x3C);
            c[0x14] = o[0x14];
            *(s32*)(c + 8) = *(s32*)(o + 8);
            *(s32*)(c + 0xC) = *(s32*)(o + 0xC) + 0x110000;
            *(s32*)(c + 0x30) = *(s32*)(o + 0x30);
            *(u8**)(c + 0x7C) = o;
            c[2] = 0;
            *(s32*)(c + 0x20) = 0;
            *(s32*)(c + 0x24) = 0xFFFA0000;
        }
    }
    func_800317B8(o);
    func_8002D9EC(o, 0x10, 0xFF);
    if (o[0x70] & 8) {
        o[0x67] = 0;
        return;
    }
    dir = *(s32*)(o + 0x24);
    if (dir < 0) {
        dir = -1;
    } else {
        dir = 1;
    }
    o[0x67] = dir;
}
