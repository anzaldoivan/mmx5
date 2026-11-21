#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern u8 D_800D1C00[];
extern u8 D_800F5FF0_ovl20[];
extern u8 D_800F61F0_ovl20[];
extern u8 D_800F63F0_ovl20[];
extern u8 D_800F65F0_ovl20[];
extern u8 D_800F67F0_ovl20[];
extern u8 D_800F69F0_ovl20[];

void func_800EFE00_ovl20(u8* arg0) {
    u8* base;
    s32 k;
    s32 t;

    if (++*(s16*)(arg0 + 8) >= 2) {
        base = D_800D1C00;
        *(s16*)(arg0 + 8) = 0;
        t = base[0x27] - 1;
        base[0x27] = t;
        k = 0x1F;
        func_8002C3CC(D_800F61F0_ovl20, D_800F5FF0_ovl20, 0x100, k - (s8)t, k);
        ((s32(*)())func_8002C338)(0x70, D_800F61F0_ovl20, 0x10);
        func_8002C3CC(D_800F65F0_ovl20, D_800F63F0_ovl20, 0x100,
                      k - *(s8*)(base + 0x27), k);
        ((s32(*)())func_8002C338)(0xB0, D_800F65F0_ovl20, 0x10);
        func_8002C3CC(D_800F69F0_ovl20, D_800F67F0_ovl20, 0x100,
                      k - *(s8*)(base + 0x27), k);
        ((s32(*)())func_8002C338)(0x40, D_800F69F0_ovl20, 0x10);
        if (*(s8*)(base + 0x27) == 0) {
            *(s32*)(arg0 + 0xAC) += 0xFFFCB440;
            arg0[2]++;
        }
    }
}

extern u8 D_800D1C00[];
extern u8 D_800F6DF0_ovl20[];
extern u8 D_800F6DFB_ovl20;

void func_800EFF4C_ovl20(u8* arg0) {
    s8 old;
    QByte
        v; // !FAKE: one-byte struct keeps the QImode value and its andi 0xFF (C0279)

    old = D_800D1C00[0x30];
    if (D_800C931C[2] & 0x8000) {
        D_800D1C00[0x30]--;
        if ((s8)D_800D1C00[0x30] < 0) {
            D_800D1C00[0x30] = D_800F6DFB_ovl20 - 1;
        }
    } else if (D_800C931C[2] & 0x2000) {
        D_800D1C00[0x30]++;
        if ((s8)D_800D1C00[0x30] >= D_800F6DFB_ovl20) {
            D_800D1C00[0x30] = 0;
        }
    }
    if (old != (s8)D_800D1C00[0x30]) {
        play_sound(5, 0, 0);
    }
    v.b = D_800F6DF0_ovl20[(s8)D_800D1C00[0x30]];
    D_800D1C00[0x2A] = v.b;
    if (D_800C931C[2] & 0x840) {
        arg0[0x49] = v.b;
        if (v.b == 5) {
            arg0[0x44] = 1;
        } else {
            arg0[0x44] = 0;
        }
        play_sound(5, 1, 0);
        *(s16*)(arg0 + 8) = 0;
        arg0[2]++;
        return;
    }
    if (D_800C931C[2] & 0x10) {
        arg0[2] = 8;
        *(s16*)(arg0 + 8) = 0;
    }
}

extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern u8 D_800D1C00[];
extern u8 D_800F5FF0_ovl20[];
extern u8 D_800F61F0_ovl20[];
extern u8 D_800F63F0_ovl20[];
extern u8 D_800F65F0_ovl20[];
extern u8 D_800F67F0_ovl20[];
extern u8 D_800F69F0_ovl20[];

void func_800F00A4_ovl20(u8* arg0) {
    u8* base;
    s32 k;

    if (++*(s16*)(arg0 + 8) > 0) {
        base = D_800D1C00;
        *(s16*)(arg0 + 8) = 0;
        if (++*(s8*)(base + 0x27) >= 0x20) {
            *(s8*)(base + 0x27) = 0x1F;
        }
        k = 0x1F;
        func_8002C3CC(D_800F61F0_ovl20, D_800F5FF0_ovl20, 0x100,
                      k - *(s8*)(base + 0x27), k);
        ((s32(*)())func_8002C338)(0x70, D_800F61F0_ovl20, 0x10);
        func_8002C3CC(D_800F65F0_ovl20, D_800F63F0_ovl20, 0x100,
                      k - *(s8*)(base + 0x27), k);
        ((s32(*)())func_8002C338)(0xB0, D_800F65F0_ovl20, 0x10);
        func_8002C3CC(D_800F69F0_ovl20, D_800F67F0_ovl20, 0x100,
                      k - *(s8*)(base + 0x27), k);
        ((s32(*)())func_8002C338)(0x40, D_800F69F0_ovl20, 0x10);
        if (*(s8*)(base + 0x27) >= 0x1F) {
            *(s8*)(base + 0x27) = 0x20;
            arg0[1] = 4;
            arg0[2] = 0;
            *(s32*)(arg0 + 0xAC) += 0x34BC0;
            base[0x2D] = 0;
        }
    }
}
