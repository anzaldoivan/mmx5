#include "types.h"
#include "mmx5/globals.h"

void func_800FDC00_ovl04(void) {
    u8* p = g_playthrough_state.u;

    p[0x27] = 0;
    p[0x2A] = 0;
    p[0x28] = 0;
    p[0x29] = 0;
    p[0x2B] = 0;
}
