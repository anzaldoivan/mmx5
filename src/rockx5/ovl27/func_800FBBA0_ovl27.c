#include "types.h"

extern void silence_sound(s32, s32);

void func_800FBBA0_ovl27(u8* arg0) {
    if (((s8*)arg0)[2] == 0) {
        silence_sound(2, 0x68);
    }
    arg0[5] = 1;
    arg0[6] = 0;
}
