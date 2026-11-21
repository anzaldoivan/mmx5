#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

void func_800FA944_ovl50(Actor50* arg0) {
    func_8002385C(0x2B, 0xFF, 0);
    play_sound(2, 0x4F, 0);
    arg0->step++;
}
