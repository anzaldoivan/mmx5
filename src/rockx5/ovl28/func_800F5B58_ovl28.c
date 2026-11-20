#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F5B58_ovl28(u8* obj) {
    s32 mask;
    u8 dir;

    animate_object(obj);
    apply_object_motion(obj);
    dir = obj[0x15];
    mask = 2;
    if (dir != 0 && (mask = 1, obj[0x15] != 0)) {
        if (*(s32*)(obj + 0x20) < 0x42000) {
            *(s32*)(obj + 0x20) = 0x42000;
        }
    } else if (*(s32*)(obj + 0x20) > -0x42000) {
        *(s32*)(obj + 0x20) = -0x42000;
    }
    if ((obj[0x70] & mask) || (s8)obj[0x45] == 2) {
        set_animation(obj, 0x1A);
        if (obj[0x15] != 0) {
            *(s32*)(obj + 0x20) = 0x42000;
        } else {
            *(s32*)(obj + 0x20) = -0x42000;
        }
        *(s32*)(obj + 0x28) = -0x3000;
        *(s8*)(obj + 0x9A) = -1;
        obj[6]++;
        play_sound(2, 0x72, obj);
    }
}
