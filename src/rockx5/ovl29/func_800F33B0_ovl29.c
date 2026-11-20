#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"

s32 func_800F33B0_ovl29(u8* arg0) {
    s32 d;
    u8* p2;

    {
        u8* p = g_Player;

        d = *(s16*)(p + 0xA) - *(s16*)(arg0 + 0xA);
        if (d >= 0) {
            d = d < 0x41;
        } else {
            d = *(s16*)(arg0 + 0xA) - *(s16*)(p + 0xA) < 0x41;
        }
    }
    if (!d || (p2 = g_Player, d = *(s16*)(p2 + 0xA) - *(s16*)(arg0 + 0xA),
               (d >= 0) ? (d >= 0x71)
                        : (*(s16*)(arg0 + 0xA) - *(s16*)(p2 + 0xA) >= 0x71))) {
        return 0;
    }
    return random_byte() < 0x61;
}
