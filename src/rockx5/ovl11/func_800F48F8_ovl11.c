#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern void silence_sound(s32, s32);
extern void start_pad_vibration(s32);

void func_800F48F8_ovl11(u8* a0) {
    if (D_800D1C28[1] < 3) {
        silence_sound(5, 0x1C);
    }
    if (a0[0x72] & 0xB) {
        start_pad_vibration(6);
        play_sound(5, 0x1C, a0);
        a0[5] = 6;
    }
}
