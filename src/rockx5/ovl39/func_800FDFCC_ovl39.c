#include "types.h"
#include "mmx5/sound.h"

void func_800FDFCC_ovl39(u8* obj) {
    play_sound(2, 0x6C, obj);
    obj[4] = 2;
}
