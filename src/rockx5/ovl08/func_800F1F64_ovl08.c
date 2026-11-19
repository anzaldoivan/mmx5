#include "types.h"
#include "mmx5/sound.h"

extern u8 D_800D1C00[];

void func_800F1F64_ovl08(u8* a0) {
    *(s32*)(a0 + 0x20) = 0;
    *(s32*)(a0 + 0x24) = 0xC000;
    a0[0x84] = 0;
    if (((s8*)a0)[3] != 0) {
        D_800D1C00[0x27]++;
        play_sound(5, 0x17, 0);
        a0[0x84] = 1;
    }
    a0[6]++;
}
