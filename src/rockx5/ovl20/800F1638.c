#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

void func_800F1638_ovl20(u8* a0) {
    s32 i;
    u8* p;

    g_playthrough_state.u[0x30] = 0;
    g_playthrough_state.u[0x31] = 0;
    a0[2]++;
    for (i = 0; i < 3; i++) {
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x2C;
            p[2] = i + 4;
        }
    }
}

void func_800F16BC_ovl20(u8* a0) {
    if (D_800C9320.h & 0x5000) {
        u8* p;
        play_sound(5, 0, 0);
        p = g_playthrough_state.u;
        if (++((s8*)p)[0x31] >= 2) {
            p[0x31] = 0;
        }
    } else if (D_800C9320.h & 0x840) {
        u8* p;
        play_sound(5, 1, 0);
        p = g_playthrough_state.u;
        if (((s8*)p)[0x31] == 0) {
            a0[2]++;
        } else {
            p[0x30] = 1;
            a0[1] = 7;
            a0[2] = 2;
        }
    }
}

#define func_800F0820_ovl24 func_800F1784_ovl20
#include "shared/func_800F0820_ovl24.c"
#undef func_800F0820_ovl24

extern signed char D_8009A424;
extern void func_800EE974_ovl20(void);

void func_800F17B8_ovl20(u8* a0) {
    if (D_8009A424 == 0) {
        a0[0] = 0x13;
        a0[1] = 0;
        a0[2] = 0;
        a0[3] = 0;
        if (a0[0xCB] & 1) {
            func_800EE974_ovl20();
            if (a0[0xCB] & 0x80) {
                a0[0x194] = 9;
                a0[0x195] = 0xB;
                a0[0x196] = 0xFF;
                a0[0x1D] = 9;
            } else {
                a0[0x194] = 0xA;
                a0[0x195] = 0xC;
                a0[0x196] = 0xFF;
                a0[0x1D] = 0xA;
            }
        } else {
            a0[0x194] = 4;
            a0[0x195] = 0xFF;
            a0[0x1D] = 4;
        }
    }
}
