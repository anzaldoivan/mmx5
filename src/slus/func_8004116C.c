#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/system.h"
#include "mmx5/sound.h"

extern s8 D_800E9548;

void func_8004116C(u8* obj) {
    if ((u8)++obj[0xF4] < 51) {
        return;
    }
    if (obj[0x17] > 0xB0) {
        func_8003B33C(obj, 0xB2);
    } else {
        func_8003B33C(obj, 0xAF);
    }
    obj[0xF4] = random_byte() % 3 + 3;
    obj[7] = 0;
    obj[6]++;
    D_800E9548 = 0;
    play_sound(1, 0x1C, obj);
}
