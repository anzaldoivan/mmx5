#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F70CC_ovl28(u8* obj) {
    animate_object(obj);
    if ((*(s8**)(obj + 0x50))[7] == 2) {
        *(s32*)(obj + 0x24) = 0x80000;
        set_animation(obj, 0x16);
        play_sound(2, 0x75, obj);
        obj[6]++;
    }
}
