#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

#define func_800F5CB8_ovl26 func_800F6278_ovl26
#include "shared/func_800F5CB8_ovl26.c"
#undef func_800F5CB8_ovl26

void func_800F62C0_ovl26(u8* obj) {
    s32 speed;
    s32 n;

    if ((*(u8**)(obj + 0x7C))[0x96] == 0) {
        speed = 0x60000;
    } else {
        speed = -0x60000;
    }
    animate_object(obj);
    obj[6]++;
    n = ((s8*)obj)[2];
    if (n < 8) {
        *(s16*)(obj + 0x90) = (n + 1) * 35;
        *(s32*)(obj + 0x20) = speed;
    } else {
        *(s16*)(obj + 0x90) = (n - 7) * 35;
        *(s32*)(obj + 0x20) = -speed;
    }
}

void func_800F6364_ovl26(u8* obj) {
    animate_object(obj);
    if (*(s16*)(obj + 0x90) != 0) {
        (*(s16*)(obj + 0x90))--;
    } else {
        set_animation(obj, 1);
        play_sound(2, 0x5E, obj);
        obj[6]++;
    }
}

#include "shared/func_800F63CC_ovl26.c"

void func_800F6414_ovl26(u8* obj) {
    s32 speed;
    s8 idx;

    if (*(u8*)(*(u8**)(obj + 0x7C) + 0x96) == 0) {
        speed = 0x60000;
    } else {
        speed = -0x60000;
    }
    animate_object(obj);
    if (*(s8*)(*(u8**)(obj + 0x7C) + 7) == 0) {
        obj[6]++;
        idx = *(s8*)(obj + 2);
        if (idx < 8) {
            *(s16*)(obj + 0x90) = (idx + 1) * 35;
            *(s32*)(obj + 0x20) = -speed;
        } else {
            *(s16*)(obj + 0x90) = (idx - 7) * 35;
            *(s32*)(obj + 0x20) = 0;
        }
    }
}

void func_800F64D0_ovl26(u8* obj) {
    animate_object(obj);
    if (*(s16*)(obj + 0x90) != 0) {
        (*(s16*)(obj + 0x90))--;
        return;
    }
    if (*(s8*)(obj + 2) < 8) {
        set_animation(obj, 1);
        play_sound(2, 0x5E, obj);
    }
    obj[6]++;
}

#define func_800F63CC_ovl26 func_800F6548_ovl26
#include "shared/func_800F63CC_ovl26.c"
#undef func_800F63CC_ovl26

#define func_800F5D00_ovl26 func_800F6590_ovl26
#include "shared/func_800F5D00_ovl26.c"
#undef func_800F5D00_ovl26
