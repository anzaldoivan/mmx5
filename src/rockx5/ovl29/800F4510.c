#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F4510_ovl29(u8* obj) {
    if (*(s16*)(obj + 0x88) - *(s16*)(obj + 0xE) >= 0x61) {
        obj[6]++;
        set_animation(obj, 4);
        play_sound(2, 0xAD, obj);
        obj[0x60] = 5;
        *(s32*)(obj + 0x24) = 0xFFFA0000;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0;
    }
    apply_object_motion(obj);
    animate_object(obj);
}

extern u8 D_800FA2E0_ovl29[][6];

void func_800F4598_ovl29(u8* obj) {
    if (*(s8*)(obj + 0x46) == 0) {
        obj[5] = D_800FA2E0_ovl29[obj[0x8D]][obj[0x8E]];
        obj[0x8E]++;
        obj[6] = 0;
    }
    animate_object(obj);
}
