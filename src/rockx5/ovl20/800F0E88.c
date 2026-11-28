#include "types.h"
#include "mmx5/globals.h"

void func_800F0E88_ovl20(u8* arg0) {
    u8* p;

    *(s16*)(arg0 + 8) += 1;
    if (*(s16*)(arg0 + 8) >= 10) {
        p = g_playthrough_state.u;
        p[0x26] = 0;
        *(s16*)(arg0 + 8) = 0;
        arg0[2]++;
        p[0x27] = 0x1F;
        p[0x2B] = 0;
    }
}

extern u8 D_800F6DF0_ovl20[];
extern u8 D_800F6DF8_ovl20;

void func_800F0ED8_ovl20(u8* arg0) {
    u8* p = g_playthrough_state.u;
    u8* obj;
    u8 idx;

    p[0x31] = 0;
    idx = D_800F6DF0_ovl20[0];
    p[0x32] = 1;
    p[0x30] = idx;
    p[0x2A] = D_800F6DF0_ovl20[(s8)idx];
    obj = func_8002D27C();
    if (obj != 0) {
        obj[0] = 0x41;
        obj[1] = 0x2B;
        obj[2] = 0;
    }
    obj = func_8002D27C();
    if (obj != 0) {
        obj[0] = 0x41;
        obj[1] = 0x2B;
        obj[2] = 1;
    }
    *(s16*)(arg0 + 8) = 0;
    arg0[2]++;
    D_800F6DF8_ovl20 = 0x1F;
}

void func_800F0F98_ovl20(u8* arg0) {
    D_800D1C32.u = 1;
    *(s16*)(arg0 + 8) = 0;
    arg0[2]++;
}

void func_800F0FB8_ovl20(u8* arg0) {
    u8* p = g_playthrough_state.u;

    p[0x2B] = 1;
    p[0x31] = 1;
    *(s16*)(arg0 + 8) = 0;
    p[0x27] = 0;
    arg0[2]++;
}

#define func_800F0820_ovl24 func_800F0FE8_ovl20
#include "shared/func_800F0820_ovl24.c"
#undef func_800F0820_ovl24

extern signed char D_8009A424;

void func_800F101C_ovl20(u8* a0) {
    s32 i;
    s32 n;
    u8* p;
    u8 b;

    if (D_8009A424 == 0) {
        for (i = 15, p = a0 + 0x35; i >= 0; i--) {
            *p-- = 0;
        }
        func_8001E668();
        func_8002C50C();
        if (a0[0x10F] == 2) {
            a0[0x10F] = 3;
        } else if (a0[0x10F] == 4) {
            a0[0x10F] = 5;
        }
        n = ((s8*)a0)[0xC];
        if (n >= 11) {
            a0[0] = 7;
        } else {
            b = a0[0x4C];
            if (n < 9 && ((b >> (n - 1)) & 1)) {
                a0[0] = 7;
            } else {
                a0[0] = 5;
            }
        }
        a0[1] = 0;
        a0[2] = 0;
        a0[3] = 0;
    }
}
