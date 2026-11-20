#include "types.h"
#include "mmx5/globals.h"

s32 func_800F033C_ovl04(void) {
    u8* p = g_Player;
    s32 r;

    r = 0;
    if (((s8*)p)[0xF3] == 0 || (u32)(p[0xFA] - 2) >= 2) {
        r = 1;
    }
    return r;
}
