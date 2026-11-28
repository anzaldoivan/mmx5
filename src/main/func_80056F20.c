#include "types.h"
#include "mmx5/globals.h"

extern u8 D_80091C44;

void func_80056F20(u8* a0) {
    u8* g;

    g_Player[0x71] |= 8;
    if (D_80091C44 == 0) {
        g = g_playthrough_state.u;
        g[0x12] = 0;
        g[0x13] = 0;
        g[0x16] = 0;
        g[0x19] = 0;
        g[0x18] = 0;
        g[0x17] = 0;
        g[0x14] = 0;
        g[0x15] = 0;
        ((s32(*)())func_8003D2C4)();
        a0[4]++;
    }
}
