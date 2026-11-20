#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern s32 D_800FB2A4_ovl00[];

void func_800F5CC4_ovl00(u8* a0) {
    if (--*(s32*)(a0 + 0x7C) != 0) {
        if ((D_8009A420_as_s32 & 7) == 0) {
            func_8004FD90(a0, 1, 0x1F, 0x1F);
        }
        if ((D_8009A420_as_s32 & 0xF) == 0) {
            play_sound(0, D_800FB2A4_ovl00[random_byte() & 3], a0);
        }
    } else {
        a0[4] = 3;
        a0[6] = 0;
    }
}
