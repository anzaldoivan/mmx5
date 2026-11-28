#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern u8 D_800750C0[];
extern u8 D_80101444_ovl04[];
extern u8 D_80101394_ovl04[];
extern u8 D_80101398_ovl04[];
extern u8 D_8010139C_ovl04[];
extern u32* D_80098118;
extern s32 func_8002B5B4(s32);
extern void func_800F1080_ovl04(u8* a0);

#define B(p, o) (*(u8*)((p) + (o)))
#define SB(p, o) (*(s8*)((p) + (o)))
#define H(p, o) (*(u16*)((p) + (o)))
#define W(p, o) (*(s32*)((p) + (o)))
#define SCR20 D_1F800020.s32s

void func_800F04AC_ovl04(u8* a0) {
    u8* p;
    u8* q;
    u8 t;

    B(a0, 0x5C) = 2;
    B(a0, 0x60) = 4;
    W(a0, 0x58) = (s32)D_800750C0;
    B(a0, 0x61) = 0;
    p = g_Player;
    t = p[0x14];
    W(a0, 0x30) = (s32)D_80101444_ovl04;
    B(a0, 0x16) = 6;
    W(a0, 0x68) = 0;
    W(a0, 0x54) = (s32)D_80101394_ovl04;
    W(a0, 0x50) = (s32)D_80101398_ovl04;
    B(a0, 0x3) = 0;
    B(a0, 0x14) = t;
    W(a0, 0x18) = W(a0, 0x8);
    W(a0, 0x1C) = W(a0, 0xC);
    set_animation(a0, 0xB);
    W(a0, 0x20) = 0;
    W(a0, 0x24) = 0;
    W(a0, 0x28) = 0;
    W(a0, 0x2C) = 0;
    switch (SB(a0, 0x2)) {
    case 0:
        W(a0, 0x68) = (s32)D_8010139C_ovl04;
        q = g_Player;
        if (W(q, 0x8) <= W(a0, 0x8)) {
            D_1F80004C.bytes[0x80] = 0;
            B(a0, 0x15) = 0;
        } else {
            D_1F80004C.bytes[0x80] = 1;
            B(a0, 0x15) = 0x40;
        }
        B(a0, 0x67) = 1;
        W(a0, 0x2C) = 0x4200;
        B(a0, 0x5) = 6;
        break;
    case 1:
        B(a0, 0x15) = 0x40;
        B(a0, 0x5) = 9;
        break;
    case 16:
    case 17:
    case 18:
    case 32:
    case 33:
    case 34:
        H(a0, 0x40) = D_80098118[func_8002B5B4(SB(a0, 0x1))] >> 7;
        W(a0, 0x3C) = (s32)SCR20 + SCR20[func_8002B5B4(SB(a0, 0x1))];
        H(a0, 0x42) = 0x7CCC;
        load_palette(0x13C, D_1F800030, 4);
        B(a0, 0x16) = 0x23;
        B(a0, 0x15) = 0x40;
        B(a0, 0x5) = 0xA;
        break;
    }
    D_1F80004C.bytes[0x82] = 0;
    D_1F80004C.bytes[0x81] = 0;
    func_800F1080_ovl04(a0);
    B(a0, 0x4) = 1;
    B(a0, 0x6) = 0;
}
