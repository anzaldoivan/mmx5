#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/ovl02.h"
#include "mmx5/sound.h"

/* Adapted from mmx6 @c1c892d src/shared/rock_10/func_800F0778.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F2974_ovl02(void* arg0) {
    ((void (*)(void*, s32))set_animation)(arg0, 3);
    M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
}

void func_800F29A8_ovl02(u8* arg0) {
    if (*(signed char*)(arg0 + 0x45) == 1) {
        D_1F80004C.scr82->flags82 = 2;
        arg0[6]++;
    }
}

#define SCR D_1F80004C.bytes

void func_800F29E4_ovl02(ObjFE130* arg0) {
    if (arg0->unk45 == 2) {
        play_sound(2, 0x24, arg0);
        func_800F2AB4_ovl02(arg0, 0x11);
    } else if (arg0->unk45 == 3) {
        arg0->unk5 = 2;
        arg0->unk6 = 0;
    } else if (arg0->unk45 == 4) {
        SCR[0x82] = 0;
    }
}
