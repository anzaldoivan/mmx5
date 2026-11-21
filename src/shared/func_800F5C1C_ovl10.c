#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"

void func_800F5C1C_ovl10(u8* obj) {
    *(s32*)(obj + 0x2C) = 0x3800;
    animate_object(obj);
    apply_object_motion(obj);
    if (obj[0x70] & 8) {
        if (*(s8*)(obj + 2) == 2) {
            (*(u8**)(obj + 0x80))[0x98] = 0;
        }
        set_animation(obj, 0x15);
        obj[6] = 1;
    }
}

void func_800F5C90_ovl10(u8* obj) {
    animate_object(obj);
    if (*(signed char*)(obj + 0x45) == 0x10) {
        play_sound(2, 0x5B, obj);
    }
    if (*(signed char*)(obj + 0x45) == 1) {
        obj[0x6] = 2;
    }
}

void func_800F5CE8_ovl10(u8* arg0) {
    arg0[0x86] = 1;
    arg0[3] = 0;
}

void func_800F5CF8_ovl10(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (*(signed char*)(obj + 0x45) == 0x10) {
        play_sound(2, 0x5B, obj);
    }
    if (*(signed char*)(obj + 0x45) == 1) {
        obj[0x86] = 1;
        obj[0x3] = 0;
    }
}

extern u8 D_80076060[];

void func_800F5D5C_ovl10(u8* obj) {
    s8 v;

    animate_object(obj);
    v = ((s8*)obj)[0x45];
    if (v == 1) {
        *(u8**)(obj + 0x58) = D_80076060;
        obj[5] = 7;
        obj[6] = v;
    }
}
