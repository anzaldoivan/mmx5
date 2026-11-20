#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F699C_ovl28(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (obj[0x70] & 8) {
        set_animation(obj, 0x1B);
        obj[0x67] = 0;
        obj[6]++;
        play_sound(2, 0x6E, obj);
    }
}
