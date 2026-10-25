#include "types.h"
#include "addr.h"

extern void func_800171E8(u8*, s32);
extern u32* D_80098118;
extern u8 D_800F560C_ovl24[];
extern Actor50 D_800F5904_ovl24[];
extern Ent3CC_Half D_800F5880_ovl24[];
extern u8 D_800F5948_ovl24[];
extern s8 D_800D1C26;

#define B(p, o) (*(u8*)((p) + (o)))
#define SB(p, o) (*(s8*)((p) + (o)))
#define H(p, o) (*(u16*)((p) + (o)))
#define W(p, o) (*(s32*)((p) + (o)))

void func_800F3ABC_ovl24(u8* a0) {
    s32 t;
    s32 v;
    s8 m;

    B(a0, 0x15) = 0;
    B(a0, 0x0) = 0x41;
    H(a0, 0x40) = D_80098118[0] >> 7;
    W(a0, 0x3C) = (s32)D_1F800020.s32s + D_1F800020.s32s[0];
    W(a0, 0x30) = (s32)D_800F560C_ovl24;
    B(a0, 0x47) = 0;
    switch (SB(a0, 0x2) & 0x80) {
    case 0:
        func_800171E8(a0, D_800F5904_ovl24[B(a0, 0x2) & 0x7F].step);
        H(a0, 0xA) = D_800F5880_ovl24[B(a0, 0x2) & 0x7F].lo;
        H(a0, 0xE) = D_800F5880_ovl24[B(a0, 0x2) & 0x7F].hi;
        if (D_800F5904_ovl24[B(a0, 0x2) & 0x7F].pad0 == 0) {
            B(a0, 0x5) = 1;
        } else {
            B(a0, 0x5) = 0;
        }
        if ((u8)(B(a0, 0x2) - 6) < 4) {
            B(a0, 0x0) = 1;
            H(a0, 0x40) = 0x1F00;
            W(a0, 0x3C) = W(D_801F3000, 0) + (s32)D_801F3000;
        }
        break;
    case 0x80:
        switch (B(a0, 0x2) & 0x7F) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            func_800171E8(a0, D_800F5948_ovl24[B(a0, 0x2) & 0xF]);
            if (B(a0, 0x56) != 0) {
                B(a0, 0x5) = 0;
                break;
            }
            B(a0, 0x5) = 1;
            break;
        case 10:
            B(a0, 0x5) = 2;
            break;
        case 11:
            B(a0, 0x5) = 3;
            break;
        case 12:
            B(a0, 0x5) = 4;
            break;
        case 13:
            B(a0, 0x5) = 5;
            break;
        case 14:
            func_800171E8(a0, 0x1A);
            B(a0, 0x5) = 6;
            break;
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
            if ((B(a0, 0x2) & 0x7F) == 0xF) {
                func_800171E8(a0, 0x3B);
                H(a0, 0xA) = 0xA0;
                H(a0, 0xE) = 0x74;
            } else if ((B(a0, 0x2) & 0x7F) == 0x10) {
                func_800171E8(a0, D_800D1C26 + 0x1A);
                H(a0, 0xA) = 0xA0;
                H(a0, 0xE) = 0x88;
            } else if ((B(a0, 0x2) & 0x7F) == 0x11) {
                func_800171E8(a0, D_800D1C26 + 0x22);
                H(a0, 0xA) = 0x18;
                H(a0, 0xE) = 0x88;
            } else if ((B(a0, 0x2) & 0x7F) == 0x12) {
                func_800171E8(a0, D_800D1C26 + 0x2A);
                H(a0, 0xA) = 0xA0;
                H(a0, 0xE) = 0x98;
            } else if ((B(a0, 0x2) & 0x7F) == 0x13) {
                func_800171E8(a0, D_800D1C26 + 0x32);
                H(a0, 0xA) = 0x18;
                H(a0, 0xE) = 0x98;
            } else if ((B(a0, 0x2) & 0x7F) == 0x14) {
                func_800171E8(a0, 0x3C);
            }
            B(a0, 0x5) = 1;
            break;
        case 91:
            func_800171E8(a0, 0x1A);
            B(a0, 0x5) = 7;
            break;
        case 92:
            func_800171E8(a0, 0x1A);
            B(a0, 0x5) = 9;
            break;
        case 93:
            func_800171E8(a0, 0xA);
            H(a0, 0xA) = 0x118;
            H(a0, 0xE) = 0x28;
            B(a0, 0x5) = 0xA;
            break;
        case 94:
            func_800171E8(a0, D_800D1C26 + 0x8F);
            H(a0, 0xA) = 0xA0;
            H(a0, 0xE) = 0xB8;
            B(a0, 0x5) = 0xB;
            break;
        }
        if (B(a0, 0x17) == 0x1A) {
            B(a0, 0x0) = 1;
            H(a0, 0x40) = 0x1D00;
            W(a0, 0x3C) = D_801F300C + (s32)D_801F3000;
        }
        t = B(a0, 0x2) & 0x7F;
        if ((u32)(t - 0x15) < 0x20) {
            func_800171E8(a0, t + 0x28);
            B(a0, 0x5) = 8;
        } else if ((u32)(t - 0x35) < 0x20) {
            func_800171E8(a0, t + 0x28);
            B(a0, 0x5) = 8;
        } else if ((u32)(t - 0x55) < 3) {
            func_800171E8(a0, t + 0x28);
            B(a0, 0x5) = 8;
        } else if ((u32)(t - 0x58) < 3) {
            func_800171E8(a0, t + 0x28);
            B(a0, 0x5) = 8;
        }
        break;
    }
    if (SB(a0, 0x55) != 0) {
        H(a0, 0xE) += SB(a0, 0x55);
    }
    SB(a0, 0x14) = -1;
    B(a0, 0x16) = 0;
    B(a0, 0x4) = 1;
    B(a0, 0x6) = 0;
    v = SB(a0, 0x45);
    m = v % 16;
    H(a0, 0x42) = m | ((v / 16 + 0x1E0) << 6);
}
