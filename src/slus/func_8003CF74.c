#include "types.h"
#include "mmx5/sound.h"

void func_8003CF74(u8* arg0, u8 arg1) {
    if (*(s8*)(arg0 + 0xEA) <= 0) {
        play_sound(3, arg1, arg0);
    }
}
