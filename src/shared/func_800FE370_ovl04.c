#include "types.h"
#include "mmx5/globals.h"

void func_800FE370_ovl04(u8* arg0) {
    s32 limit;

    limit = 300;
    g_playthrough_state.u[0x28] &= ~arg0[0x93];
    g_playthrough_state.u[0x29] &= ~arg0[0x93];
    if (g_playthrough_state.u[0x26] & 2) {
        limit = 50;
    }
    if (++*(s32*)(arg0 + 0x84) >= limit) {
        *(s32*)(arg0 + 0x84) = 0;
        arg0[5]++;
    }
}

void func_800FE3EC_ovl04(u8* arg0) {
    g_playthrough_state.u[0x28] &= ~arg0[0x93];
    g_playthrough_state.u[0x29] &= ~arg0[0x93];
    arg0[3] = 0;
}
