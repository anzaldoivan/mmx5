#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern void silence_sound(s32, s32);

void func_8003F8EC(u8* arg0) {
    func_8003B33C(arg0, 0x5F);
    silence_sound(0xFF, 0);
    play_sound(1, 0x13, arg0);
    arg0[0x67] = 1;
    arg0[0x5] = 0x26;
    arg0[0x6] = 0;
}
