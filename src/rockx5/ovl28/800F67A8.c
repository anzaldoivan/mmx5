#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/movement.h"
#include "mmx5/sound.h"

#define D_8007BD4C D_800FE2B0_ovl28

#define func_800532E0 func_800F67A8_ovl28
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800F67E4_ovl28.c"

extern s32 D_8009A0A8;

void func_800F6820_ovl28(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 7) == 2) {
        set_animation(obj, 4);
        D_1F80004C.bytes[0x8C] = 0;
        animate_object(obj);
        obj[0x67] = 1;
        if (D_8009A0A8 > *(s32*)(obj + 8)) {
            *(s32*)(obj + 0x20) = -0x20000;
            obj[0x15] = 0;
        } else {
            *(s32*)(obj + 0x20) = 0x20000;
            obj[0x15] = 0x40;
        }
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0x5D000;
        *(s32*)(obj + 0x2C) = 0x4200;
        obj[6]++;
    }
}

void func_800F68D4_ovl28(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (*(s32*)(obj + 0x24) <= 0) {
        obj[7] = 3;
        set_animation(obj, 9);
        *(s16*)(obj + 0x7C) = 0;
        *(s16*)(obj + 0x7E) = 0;
        obj[6]++;
    }
}

void func_800F6934_ovl28(u8* obj) {
    animate_object(obj);
    if (D_1F80004C.bytes[0x8C] == 1) {
        set_animation(obj, 5);
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s8*)(obj + 0x67) = -1;
        obj[7] = 0;
        obj[6]++;
    }
}

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

#define func_800F6238_ovl28 func_800F6A04_ovl28
#include "shared/func_800F6238_ovl28.c"
#undef func_800F6238_ovl28
