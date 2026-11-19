#include "types.h"
#include "mmx5/sound.h"

extern void func_800F72C0_ovl26(void*, u8);

void func_800F7268_ovl26(u8* arg0) {
    func_800F72C0_ovl26(arg0, ((s8*)arg0)[2] * 2);
    play_sound(2, 0x5C, arg0);
    arg0[6]++;
}
