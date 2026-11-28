#include "types.h"
#include "mmx5/globals.h"

s32 func_800EFC48_ovl24(void) {
    u8* p;

    p = g_playthrough_state.u;
    if ((p[0xA1] & 0xF) == 0xF && (p[0xCC] & 0xF) != 0xF) {
        p[0x4A] |= 2;
        return 1;
    }
    p = g_playthrough_state.u;
    if ((p[0xA1] & 0xF0) == 0xF0 && (p[0xCC] & 0xF0) != 0xF0) {
        p[0x4A] |= 4;
        return 2;
    }
    if (p[0x4B] == 1) {
        p[0x4B] = 2;
        p[0x4A] |= 8;
        return 3;
    }
    return 0;
}
