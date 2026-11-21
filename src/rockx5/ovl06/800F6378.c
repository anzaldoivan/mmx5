#include "types.h"
#include "addr.h"
#include "mmx5/system.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern s32 func_8002B5B4(s32);
extern u8 D_8009A0B4;
extern u32* D_80098118;
extern u8 D_800FEABC_ovl06[];
extern u8 D_800FEAB8_ovl06[];
extern u8 D_800750C0[];
extern s16 D_8009A21C;
extern u8 D_800FEA78_ovl06[];
extern u8 D_800FEA38_ovl06[];
extern u8 D_800767E0[];

void func_800F6378_ovl06(u8* a0) {
    s32 r;
    s32 r2;
    u8 k;
    u32* t;

    a0[0] = 0x41;
    a0[4]++;
    a0[0x14] = D_8009A0B4;
    *(u16*)(a0 + 0x40) = D_80098118[func_8002B5B4(0x8B)] >> 7;
    r = func_8002B5B4(0x8B);
    t = D_1F800020.u32s;
    *(s32*)(a0 + 0x3C) = (s32)t + t[r];
    r = func_8002B5B4(0x8B);
    r2 = func_8002B5B4(0x8B);
    *(s16*)(a0 + 0x42) = ((r * 4 + 0x18) % 16) | (((r2 + 6) / 4 + 0x1E0) << 6);
    a0[0x16] = 7;
    k = a0[2];
    a0[0x61] = 0;
    a0[0xA2] = 1;
    a0[0x75] = 1;
    a0[0x76] = 0;
    a0[0x47] = k;
    if ((s8)k >= 8) {
        a0[0x5C] = 0x20;
        a0[0x47] = 8;
        *(u8**)(a0 + 0x68) = D_800FEABC_ovl06;
        *(u8**)(a0 + 0x54) = D_800FEAB8_ovl06;
        *(u8**)(a0 + 0x58) = D_800750C0;
        a0[4]++;
        *(s16*)(a0 + 0x82) = D_8009A21C;
    } else {
        a0[0x5C] = 4;
        *(u8**)(a0 + 0x68) = D_800FEA78_ovl06 + (s8)k * 16;
        *(u8**)(a0 + 0x54) = D_800FEA38_ovl06 + (s8)k * 16;
        a0[0x65] = 0;
        *(u8**)(a0 + 0x58) = D_800767E0;
        a0[0] |= 8;
    }
}

extern u8 D_8009A1F8[];
extern s32 D_800FE9F8_ovl06[];
extern s32 D_800FEA18_ovl06[];

void func_800F652C_ovl06(u8* arg0) {
    s32 n;
    s32 i;
    s32 x;
    u8* p;
    u8* o;

    n = 4;
    if (((s8*)arg0)[2] == 2) {
        n = 6;
    }
    if (((s8*)arg0)[2] >= 8) {
        p = D_8009A1F8;
        *(u16*)(p + 0x24) = *(u16*)(arg0 + 0x82);
        x = ((s8*)arg0)[2];
        n = 8;
        if (x == 8) {
            *(s16*)(p + 0x26) = 0x4F0;
        } else if (x == 9) {
            *(s16*)(p + 0x26) = 0x770;
        } else {
            *(s16*)(p + 0x26) = 0xA00;
        }
    }
    for (i = 0; i < n; i++) {
        o = func_8002D27C();
        if (o != 0) {
            o[0] = 0x41;
            o[1] = 0x21;
            o[0x15] = random_byte() & 0x40;
            o[2] = arg0[2];
            *(s32*)(o + 8) =
                *(s32*)(arg0 + 8) + D_800FE9F8_ovl06[random_byte() & 7];
            *(s32*)(o + 0xC) =
                *(s32*)(arg0 + 0xC) + D_800FEA18_ovl06[random_byte() & 7];
            *(s32*)(o + 0x3C) = *(s32*)(arg0 + 0x3C);
            *(u16*)(o + 0x40) = *(u16*)(arg0 + 0x40);
            *(u16*)(o + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
            o[0x14] = g_Player[0x14];
        }
        if (i & 1) {
            func_8004FD90(arg0, 1, 0xF, 0xF);
        }
    }
    clear_object_slot(arg0);
}
