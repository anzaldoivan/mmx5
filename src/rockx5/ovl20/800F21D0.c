#include "types.h"
#include "addr.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u32* D_80098118;
extern u8 D_800F53F8_ovl20[];
extern u16 D_800F5404_ovl20[][2];

void func_800F21D0_ovl20(u8* o) {
    s8 s;
    s32* p;
    u8* g;
    u16(*tb)[2];
    u8* h;
    s32 v;
    s32 r;
    s32 t;

    s = ((s8*)o)[2];
    ((s16*)o)[0x20] = *D_80098118 >> 7;
    p = D_1F800020.s32s;
    ((u8**)o)[0xF] = (u8*)p + *p;
    ((u8**)o)[0xC] = D_800F53F8_ovl20;
    if (s == 0) {
        ((s16*)o)[0x21] = 0x7800;
        o[0x16] = 3;
        tb = D_800F5404_ovl20;
        h = g_playthrough_state.u;
        ((u16*)o)[5] = tb[((s8*)h)[0x28]][0];
        ((u16*)o)[7] = D_800F5404_ovl20[((s8*)h)[0x28]][1];
        ((s32(*)())set_animation)(o, 0);
    } else if (s == 1) {
        ((s16*)o)[0x21] = 0x7800;
        o[0x16] = 0x21;
        ((s32(*)())set_animation)(o, 1);
    } else {
        ((s16*)o)[0x21] = 0x7800;
        o[0x16] = 0x22;
        ((s32(*)())set_animation)(o, 2);
        t = o[2] & 0xF;
        if (t == 8) {
            g = g_playthrough_state.u;
            r = g[0x10F];
            if (r == 2) {
                r = 8;
            } else if (r == 4) {
                r = 9;
            } else {
                r = 10;
                if (g[0x79] >= 9) {
                    r = 11;
                }
            }
            v = r;
        } else {
            v = t;
        }
        o[2] = v | 0x10;
    }
    o[0x14] = 1;
    o[0x15] = 0;
    o[4]++;
}

extern u16 D_800F5404_ovl20[][2];
extern u16 D_800F5428_ovl20[][2];

static inline s32 func_800F2348_sel(void) {
    u8* p = g_playthrough_state.u;
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
        u8* q = g_playthrough_state.u;
        *(u16*)(a0 + 0xA) = t0[((s8*)q)[0x28]][0];
        *(u16*)(a0 + 0xE) = D_800F5404_ovl20[((s8*)q)[0x28]][1];
    } else if (((s8*)a0)[2] == 1) {
        p = g_playthrough_state.u;
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
        u8* g = g_playthrough_state.u;
        if (((s8*)g)[0x26] != 0) {
            a0[3] = 0;
            a0[4]++;
        } else {
            func_8002D89C(a0);
        }
    }
}
