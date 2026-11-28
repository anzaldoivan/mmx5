#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/system.h"

void func_800FF2F8_ovl04(u8* arg0) {
    u8* g = g_playthrough_state.u;

    if (((s8*)g)[0x28] == 0) {
        if (arg0[0x8D] == 0 || --arg0[0x8D] == 0) {
            g[0x28] = 1 << (random_byte() & 3);
            arg0[0x8D] = 0x3C;
        }
    }
}
