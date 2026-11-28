#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern void func_800F1148_ovl11(u8* obj);
extern void func_800F0F78_ovl11(u8* obj);

void func_800F0AE0_ovl11(u8* obj) {
    animate_object(obj);
    if (g_playthrough_state.s[0x44] != (*(s32*)(obj + 0x84) & 1)) {
        set_animation(obj, 2);
    } else {
        set_animation(obj, 1);
    }
    if (*(s8*)(obj + 2) == 0) {
        if (*(s32*)(obj + 0x84) == 2 && g_playthrough_state.s[0x44] == 0) {
            play_sound(2, 0x2F, obj);
            func_800F1148_ovl11(obj);
        } else {
            play_sound(2, 0x2F, obj);
            func_800F0F78_ovl11(obj);
        }
    } else {
        play_sound(2, 0x2F, obj);
        func_800F0F78_ovl11(obj);
    }
    *(s16*)(obj + 0x7C) = 0x4B;
    if (*(s8*)(obj + 2) == 2) {
        *(s16*)(obj + 0x7C) = 0x32;
    }
    obj[6]++;
}

/* Adapted from mmx6 @c1c892d src/shared/rock_15/func_800EC0E8.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_800D1C44;

void func_800F0BE8_ovl11(void* arg0) {
    s32 var_v0;
    s8 temp_s1;

    ((void (*)())animate_object)();
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, u8*, 6) = 0;
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            // !FAKE: pins t to $2; gcc 2.7.2 allocates another register without it (byte mismatch)
            register s32 t asm("$2") = M2C_FIELD(arg0, s32*, 0x84) + 1;
            M2C_FIELD(arg0, s32*, 0x84) = t;
            var_v0 = t < D_800D1C44 + 3;
        } else {
            var_v0 = M2C_FIELD(arg0, s32*, 0x84) + 1;
            M2C_FIELD(arg0, s32*, 0x84) = var_v0;
            var_v0 = var_v0 < 4;
        }
        if (var_v0 == 0) {
            temp_s1 = M2C_FIELD(arg0, s8*, 2);
            if (temp_s1 == 2) {
                set_animation(arg0, 0);
                M2C_FIELD(arg0, u8*, 5) = temp_s1;
                M2C_FIELD(arg0, u16*, 0x7C) = 0x78;
            } else {
                M2C_FIELD(arg0, u8*, 5) = 4;
                M2C_FIELD(arg0, u16*, 0x7C) = 0x14;
            }
            M2C_FIELD(arg0, s32*, 0x84) = 0;
        }
    }
}
