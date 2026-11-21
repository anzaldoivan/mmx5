#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"

#define D_8007BD4C D_800FA238_ovl26

#define func_800532E0 func_800F5F5C_ovl26
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

void func_800F5F98_ovl26(u8* a0) {
    if (*(s16*)(a0 + 0x90) != 0) {
        *(s16*)(a0 + 0x90) -= 1;
        return;
    }
    a0[6]++;
}

extern X4_S16Pair D_800F9F24_ovl26[][16];

void func_800F5FC4_ovl26(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        move_object(obj);
        if (*(s16*)(obj + 0xE) <=
            D_800F9F24_ovl26[obj[0x94]][*(s8*)(obj + 2)].lo) {
            *(s16*)(obj + 0xE) =
                D_800F9F24_ovl26[obj[0x94]][*(s8*)(obj + 2)].lo;
            set_animation(obj, 0);
            obj[6]++;
        }
    }
}

#define func_800F5CB8_ovl26 func_800F6054_ovl26
#include "shared/func_800F5CB8_ovl26.c"
#undef func_800F5CB8_ovl26

void func_800F609C_ovl26(u8* obj) {
    s32 n;

    animate_object(obj);
    if (((s8*)*(u8**)(obj + 0x7C))[7] == 0x10) {
        obj[6]++;
        if (obj[0x94] < 3) {
            n = ((s8*)obj)[2];
            n++;
        } else {
            n = ((s8*)obj)[2];
            if (n >= 8) {
                return;
            }
            n++;
        }
        *(s16*)(obj + 0x90) = n * 35;
    }
}

void func_800F6124_ovl26(u8* obj) {
    animate_object(obj);
    if (*(s16*)(obj + 0x90) != 0) {
        *(s16*)(obj + 0x90) -= 1;
        return;
    }
    if (obj[0x94] < 3) {
        obj[5] = 0;
        play_sound(2, 0x5E, obj);
        set_animation(obj, 1);
    } else {
        obj[5] = 5;
        if (*(s8*)(obj + 2) < 8) {
            set_animation(obj, 1);
            play_sound(2, 0x5E, obj);
        }
    }
    obj[6] = 0;
    if ((*(u8**)(obj + 0x7C))[0x96]) {
        *(s32*)(obj + 0x20) = 0x60000;
    } else {
        *(s32*)(obj + 0x20) = 0xFFFA0000;
    }
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    (*(u8**)(obj + 0x7C))[0x97] = 0;
}
