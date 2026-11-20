#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern u16 D_800C9320;
extern u8 D_800D1F28[];

void func_8001DDF4(void) {
    if (D_800C9320 & 0x40) {
        play_sound(0, 0x22, 0);
        ((s32(*)())func_8002C50C)();
        D_800D1F28[0] = 7;
        D_800D1F28[1] = 5;
    }
}
