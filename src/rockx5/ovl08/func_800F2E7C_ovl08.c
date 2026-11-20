#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

void func_800F2E7C_ovl08(u8* a0) {
    u8* p = g_Player;

    if (*(s16*)(p + 0xA) >= 0x196) {
        *(s16*)(p + 0xA) = 0x195;
    }
    if (*(s8*)(a0 + 0x45) == 1) {
        play_sound(5, 0x15, a0);
        a0[5] = 2;
        a0[6] = 0;
    }
}
