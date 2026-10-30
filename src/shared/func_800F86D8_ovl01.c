/* Shared body (DK-5), from the banked draft of func_800F86D8_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern u8 D_80074EE0[];
extern u8 D_80075C00[];
extern u8 D_8009A11A;
extern u8 D_800D1C00[];
extern u8 D_800FDA5C_ovl01[];
extern void* D_800FDAC4_ovl01[];

void DEDUP_NAME(u8* a0) {
    u8* base;
    s32 x;
    s32 r;
    u8 c;

    *(s32*)(a0 + 0x18) = *(s32*)(a0 + 0x8);
    *(s32*)(a0 + 0x1C) = *(s32*)(a0 + 0xC);
    base = D_800D1C00;
    x = 0x1F0;
    if (*(s8*)(base + 0xC) != 0xC) {
        x = 0x24F0;
    }
    c = D_800FDA5C_ovl01[((*(s16*)(a0 + 0xA) - x) / 16) * 2];
    a0[3] = 0;
    a0[0x7A] = 1;
    a0[0x92] = c;
    if (*(s8*)(a0 + 0x94) == 0) {
        a0[0x7A] = 0;
        func_8002D9EC(a0, 0x60, 0x60);
        func_800317B8(a0);
    }
    if (*(s8*)(a0 + 0x5C) < (s8)(*(s8*)(base + 0xA2) / 3)) {
        a0[0x89] = 2;
        if (*(s8*)(a0 + 5) == 8) {
            a0[0x93] = 1;
        }
    }
    ((void (*)(u8*))D_800FDAC4_ovl01[*(s8*)(a0 + 5)])(a0);
    r = func_80031DD0(a0);
    a0[0x82] = 0;
    if (*(s8*)(a0 + 0x80) == 0) {
        if (r < 0) {
            D_8009A11A = 1;
            a0[4] = 2;
            a0[5] = 0;
            return;
        }
        if (r != 0 && r != 0x7F) {
            a0[0x82] = 1;
            *(u8**)(a0 + 0x58) = D_80074EE0;
            *(u16*)(a0 + 0x42) |= 0x8000;
            if ((u32)(r - 0x19) < 2) {
                a0[0x80] = 2;
            } else {
                a0[0x80] = 0x1E;
            }
            if (r == 8 || r == 0x11 || r == 0x2C) {
                if (*(s8*)(a0 + 5) != 8) {
                    a0[0x60] = 6;
                    a0[5] = 0xA;
                    a0[6] = 0;
                }
            }
        }
    } else {
        a0[0x80] = a0[0x80] - 1;
        if (*(s8*)(a0 + 0x80) == 0) {
            *(u8**)(a0 + 0x58) = D_80075C00;
            *(u16*)(a0 + 0x42) &= 0x7FFF;
        } else if (!(a0[0x80] & 1)) {
            *(u16*)(a0 + 0x42) |= 0x8000;
        } else {
            *(u16*)(a0 + 0x42) &= 0x7FFF;
        }
    }
    if (*(s8*)(a0 + 5) == 9 && *(s8*)(a0 + 6) < 2) {
        a0[3] = 0;
    }
}
