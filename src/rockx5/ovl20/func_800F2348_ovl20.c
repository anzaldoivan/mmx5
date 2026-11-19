#include "types.h"
#include "mmx5/globals.h"

extern u8 D_800D1C00[];
extern u16 D_800F5404_ovl20[][2];
extern u16 D_800F5428_ovl20[][2];

static inline s32 func_800F2348_sel(void) {
    u8* p = D_800D1C00;
    s32 r = ((s8*)p)[0x28];

    if (r == 8) {
        r = p[0x10F];
        if (r == 2) {
            r = 8;
        } else if (r == 4) {
            r = 9;
        } else {
            r = 10;
            if (p[0x79] >= 9) {
                r = 11;
            }
        }
    }
    return r;
}

void func_800F2348_ovl20(u8* a0) {
    u8* p;
    s32 i;

    if (((s8*)a0)[2] == 0) {
        u16(*t0)[2] = D_800F5404_ovl20;
        u8* q = D_800D1C00;
        *(u16*)(a0 + 0xA) = t0[((s8*)q)[0x28]][0];
        *(u16*)(a0 + 0xE) = D_800F5404_ovl20[((s8*)q)[0x28]][1];
    } else if (((s8*)a0)[2] == 1) {
        p = D_800D1C00;
        if (((s8*)p)[0x28] == 8) {
            i = func_800F2348_sel();
        } else {
            i = ((s8*)p)[0x28];
        }
        *(u16*)(a0 + 0xA) = D_800F5428_ovl20[i][0];
        *(u16*)(a0 + 0xE) = D_800F5428_ovl20[func_800F2348_sel()][1];
    } else {
        u16(*t2)[2] = D_800F5428_ovl20;
        s32 j = a0[2] & 0xF;
        *(u16*)(a0 + 0xA) = t2[j][0];
        *(u16*)(a0 + 0xE) = D_800F5428_ovl20[j][1];
    }
    {
        u8* g = D_800D1C00;
        if (((s8*)g)[0x26] != 0) {
            a0[3] = 0;
            a0[4]++;
        } else {
            func_8002D89C(a0);
        }
    }
}
