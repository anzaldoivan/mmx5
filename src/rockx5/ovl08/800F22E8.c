#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/globals.h"

extern s32 func_8002B5B4(s32);
extern u8 D_800750C0[];
extern u8 D_80076A60;
extern u32* D_80098118;
extern u8 D_8009A0B4;
extern u8 D_800F3EFC_ovl08;
extern u8 D_800F3F38_ovl08;
extern u8 D_800F3F3C_ovl08;
extern u8 D_800F3F40_ovl08;

void func_800F22E8_ovl08(u8* p) {
    s32 a;
    s32 b;
    s8 mode;

    p[0] = 0x41;
    *(u16*)(p + 0x40) = D_80098118[func_8002B5B4(0x90)] >> 7;
    *(s32*)(p + 0x3C) =
        (s32)D_1F800020.s32s + D_1F800020.s32s[func_8002B5B4(0x90)];
    a = func_8002B5B4(0x90);
    b = func_8002B5B4(0x90);
    *(u16*)(p + 0x42) = ((a * 4 + 0x18) % 16) | (((b + 6) / 4 + 0x1E0) << 6);
    p[0x75] = 1;
    p[0x76] = 0;
    p[0x67] = 0;
    *(u8**)(p + 0x30) = &D_800F3EFC_ovl08;
    p[0x14] = D_8009A0B4;
    mode = ((s8*)p)[2];
    p[0x16] = 6;
    p[0x15] = 0;
    p[0x65] = 0;
    p[0x61] = 0;
    if (mode == 0) {
        p[0x5C] = 0x20;
        *(u8**)(p + 0x58) = D_800750C0;
        *(s32*)(p + 0x50) = 0;
        *(u8**)(p + 0x54) = &D_800F3F38_ovl08;
        *(u8**)(p + 0x68) = &D_800F3F3C_ovl08;
        set_animation(p, 3);
        p[4] = 1;
        p[5] = 0;
        p[6] = 0;
    } else if (mode == 1) {
        p[0x16] = 0x21;
        p[0x5C] = 4;
        *(u8**)(p + 0x58) = &D_80076A60;
        *(s32*)(p + 0x50) = 0;
        *(u8**)(p + 0x54) = &D_800F3F40_ovl08;
        *(s32*)(p + 0x68) = 0;
        set_animation(p, 0xB);
        p[3] = 0;
        p[4] = 4;
        p[5] = 0;
        p[6] = 0;
    } else if (mode == 2) {
        p[0x16] = 1;
        set_animation(p, 9);
        *(s32*)(p + 0x58) = 0;
        *(s32*)(p + 0x50) = 0;
        *(s32*)(p + 0x54) = 0;
        *(s32*)(p + 0x68) = 0;
        p[4] = 1;
        p[5] = 0;
        p[6] = 0;
    }
}

extern s32 func_8003240C(u8* a0);

void func_800F24C0_ovl08(u8* obj) {
    s8 r;
    u8* p;

    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    func_8002D89C(obj);
    func_8003240C(obj);
    r = func_80031DD0(obj);
    if (r < 0) {
        obj[4] = 2;
        *(s32*)(obj + 0x7C) = 0;
        *(s32*)(obj + 0x20) = 0;
        *(u16*)(obj + 0xA) += 8;
        *(u16*)(obj + 0xE) += 8;
        p = ((u8 * (*)()) func_8004FD90)(obj, 1, 0x1F, 0x3F);
        if (p != 0) {
            p[0x16] = 0;
        }
        p = ((u8 * (*)()) func_8004FD90)(obj, 1, 0x1F, 0x3F);
        if (p != 0) {
            p[0x16] = 0;
        }
        p = ((u8 * (*)()) func_8004FD90)(obj, 1, 0x1F, 0x3F);
        if (p != 0) {
            p[0x16] = 0;
        }
        p = ((u8 * (*)()) func_8004FD90)(obj, 1, 0x1F, 0x3F);
        if (p != 0) {
            p[0x16] = 0;
        }
        *(u16*)(obj + 0x42) &= 0x7FFF;
        *(u16*)(obj + 0xA) -= 8;
        *(u16*)(obj + 0xE) -= 8;
        return;
    }
    if (r > 0) {
        *(u16*)(obj + 0x42) |= 0x8000;
    } else {
        *(u16*)(obj + 0x42) &= 0x7FFF;
    }
}
