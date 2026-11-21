#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern u16 D_800C9320;
extern u8 D_8009A427;

void func_800F30D8_ovl24(u8* arg0) {
    if (D_800C9320 & 0x40) {
        play_sound(0, 0x22, 0);
        ((s32(*)())func_8002C50C)();
        D_8009A427 = 0;
        arg0[1] = 9;
        arg0[2] = 0;
    }
}

#define D_800EEC60_ovl00 func_800F3134_ovl24
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
