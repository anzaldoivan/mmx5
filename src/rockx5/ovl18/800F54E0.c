#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

#include "shared/func_800F54E0_ovl18.c"

extern s32 func_8002E024(void*, void*);
extern void set_velocity_from_angle(void*, s32);

void func_800F5500_ovl18(u8* obj) {
    s32 vy;
    s32 vx;

    if (--*(s16*)(obj + 0x7C) == 0) {
        *(s16*)(obj + 0x7C) = 0x5A;
        set_velocity_from_angle(obj, func_8002E024(obj, g_Player));
        vx = *(s32*)(obj + 0x20);
        vy = *(s32*)(obj + 0x24);
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x28) = -((vx * 0x2D) >> 8);
        *(s32*)(obj + 0x2C) = -((vy * 0x2D) >> 8);
        set_animation(obj, 1);
        obj[5] = 3;
        *(s32*)(obj + 0x84) = 0;
        obj[0x80]++;
        play_sound(2, 0x9D, obj);
    }
    animate_object(obj);
}

#define func_800EF574_ovl09 func_800F55DC_ovl18
#include "shared/func_800EF574_ovl09.c"
#undef func_800EF574_ovl09
