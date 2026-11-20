#include "types.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"

void func_800F7060_ovl28(u8* a0) {
    move_object(a0);
    if (*(s16*)(a0 + 0xE) >= 0x2FE) {
        *(s16*)(a0 + 0xE) = 0x2FE;
        play_sound(2, 0x6E, a0);
        a0[6]++;
        if (*(s8*)(a0 + 2) != 0) {
            (*(u8**)(a0 + 0x50))[7] = 1;
        }
    }
}
