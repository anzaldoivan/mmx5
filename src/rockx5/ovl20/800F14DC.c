#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

void func_800F14DC_ovl20(u8* arg0) {
    u8* p;
    s32 i;

    D_800D1C30.u = 0;
    arg0[2]++;
    for (i = 0; i < 4; i++) {
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x2E;
            p[2] = i + 8;
        }
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x2E;
            p[2] = i + 12;
        }
    }
    p = func_8002D27C();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x2E;
        p[2] = 0x10;
    }
}

void func_800F15A0_ovl20(u8* arg0) {
    if (D_800C9320.h & 0x10) {
        play_sound(5, 1, 0);
        arg0[1] = 7;
        arg0[2] = 2;
        D_800D1C30.u = 1;
    }
}
