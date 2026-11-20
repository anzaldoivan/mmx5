#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F616C_ovl28(u8* obj) {
    s32 vx;

    animate_object(obj);
    apply_object_motion(obj);
    vx = *(s32*)(obj + 0x20);
    if ((vx > 0 && (obj[0x70] & 1)) || (vx < 0 && (obj[0x70] & 2))) {
        obj[0x9A] = 1;
        play_sound(2, 0x70, obj);
        obj[5] = 8;
        obj[6] = 0;
    }
    if (obj[0x70] & 8) {
        play_sound(2, 0x6E, obj);
        set_animation(obj, 0x1B);
        obj[0x67] = 0;
        obj[6]++;
    }
}
