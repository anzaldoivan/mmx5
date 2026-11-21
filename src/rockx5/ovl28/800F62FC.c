#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "addr.h"

extern s32 spawn_wall_jump_visual(u8* obj);

void func_800F62FC_ovl28(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        spawn_wall_jump_visual(obj);
        obj[6]++;
    }
}

void func_800F6348_ovl28(u8* obj) {
    apply_object_motion(obj);
    animate_object(obj);
    if (*(s32*)(obj + 0x24) <= 0) {
        set_animation(obj, 5);
        *(s8*)(obj + 0x67) = -1;
        obj[6]++;
    }
}

void func_800F63A0_ovl28(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (obj[0x70] & 8) {
        ((s8*)obj)[0x9A] = -1;
        set_animation(obj, 0x1B);
        obj[0x67] = 0;
        obj[6]++;
        play_sound(2, 0x6E, obj);
    }
}

#define func_800F6238_ovl28 func_800F6410_ovl28
#include "shared/func_800F6238_ovl28.c"
#undef func_800F6238_ovl28
