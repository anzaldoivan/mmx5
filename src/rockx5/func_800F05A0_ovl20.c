#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern u16 D_800C931C[];
extern s8 D_800D1C00[];
extern s32 D_800F51F0_ovl20[];
extern s8 D_800F5238_ovl20[];

void func_800F05A0_ovl20(u8* obj) {
    s32 w;
    s32* slot;
    s32 base;
    s32 off;
    s32 bits;
    s32 mask;
    s32* tbl;
    s32 j;
    s32 idx;
    s32 have;
    s8 n;
    s8 last;
    s8 old;
    u16 pad;

    if (D_800D1C00[0x32] != -1) {
        if (D_800C931C[2] & 0xF000) {
            func_80016490(5, 0, 0);
            pad = D_800C931C[2];
            if (pad & 0x8000) {
                switch (D_800D1C00[0x32]) {
                case 0:
                case 4:
                case 8:
                case 12:
                    D_800D1C00[0x32] += 3;
                    break;
                default:
                    D_800D1C00[0x32] -= 1;
                    break;
                }
            } else if (pad & 0x2000) {
                switch (D_800D1C00[0x32]) {
                case 3:
                case 7:
                case 11:
                case 15:
                    D_800D1C00[0x32] -= 3;
                    break;
                default:
                    D_800D1C00[0x32] += 1;
                    break;
                }
            } else if (pad & 0x1000) {
                switch (D_800D1C00[0x32]) {
                case 0 ... 3:
                    D_800D1C00[0x32] += 12;
                    break;
                default:
                    D_800D1C00[0x32] -= 4;
                    break;
                }
            } else if (pad & 0x4000) {
                switch (D_800D1C00[0x32]) {
                case 12 ... 15:
                    D_800D1C00[0x32] -= 12;
                    break;
                default:
                    D_800D1C00[0x32] += 4;
                    break;
                }
            }
        }
        if (D_800C931C[2] & 0x840) {
            tbl = D_800F51F0_ovl20;
            idx = D_800D1C00[0x32];
            have = *(s32*)(obj + 0x84);
            mask = tbl[idx];
            if (have & mask) {
                if (D_800F5238_ovl20[idx + D_800D1C00[0x2A] * 16] != 0) {
                    old = D_800D1C00[0x31];
                    off = D_800D1C00[0x2A] << 2;
                    base = (s32)obj + 0x88;
                    slot = (s32*)(base + off);
                    if (*slot & mask) {
                        *slot &= ~mask;
                    } else if (old < D_800D1C00[0x30]) {
                        *slot |= mask;
                    }
                    w = (s32)obj + 0x88;
                    last = 0;
                    n = 0;
                    bits = *(s32*)(w + (D_800D1C00[0x2A] << 2));
                    for (j = 0; j < 0x10; j++) {
                        if (bits & D_800F51F0_ovl20[j]) {
                            last = ++n;
                        }
                    }
                    D_800D1C00[0x31] = last;
                    if (last != old) {
                        func_80016490(5, 1, 0);
                    }
                }
            }
        }
    }
    if (D_800C931C[2] & 0x10) {
        func_80016490(5, 1, 0);
        obj[1] = 5;
        obj[2] = 3;
    }
}
