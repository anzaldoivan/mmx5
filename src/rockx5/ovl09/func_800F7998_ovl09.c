#include "types.h"
#include "mmx5/globals.h"

extern s8 D_8009A170;

void func_800F7998_ovl09(u8* p) {
    u8* d;
    u8 t;

    if (D_8009A170 < 0) {
        func_8003D2C4();
        d = g_playthrough_state.u;
        t = p[2];
        ((s8*)d)[0xF] = -0x40;
        d[0x1D] = t & 0xF;
        p[4] = 3;
        p[5] = 0;
    }
}
