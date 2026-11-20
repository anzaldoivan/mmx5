#include "types.h"
#include "mmx5/globals.h"

s32 func_800F2E90_ovl10(u8* a0) {
    u8* p = g_Player;

    if (((s8*)p)[0xCA] == 0 && func_800317B8(a0) != 0 && ((s8*)p)[0xCA] != 0) {
        return 1;
    }
    return 0;
}
