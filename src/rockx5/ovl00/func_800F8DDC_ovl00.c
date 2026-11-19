#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void func_800F8DDC_ovl00(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == -1) {
        *(s16*)(obj + 0xA) = 0x127C;
        *(s16*)(obj + 0xE) = 0x11C;
        *(s16*)(obj + 0x7C) = 0xF;
        play_sound(2, 4, obj);
        obj[6]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}
