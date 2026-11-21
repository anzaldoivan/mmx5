#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

/* Adapted from mmx6 @c1c892d src/shared/rock_06/func_800EB41C.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s32 D_80074E40;
extern s32 D_800F3B44_ovl08;
extern s32 D_800F3B48_ovl08;

void func_800EF6C8_ovl08(void* arg0) {
    s32 var_a1;
    u8 temp_v1;
    s32 temp_v0;

    var_a1 = 0xFFFD8000;
    M2C_FIELD(arg0, u8*, 3) = 1;
    temp_v1 = M2C_FIELD(arg0, u8*, 0x15);
    M2C_FIELD(arg0, u8*, 4) = M2C_FIELD(arg0, u8*, 4) + 1;
    if (temp_v1 != 0) {
        var_a1 = 0x28000;
    }
    temp_v0 = M2C_FIELD(arg0, s16*, 0xA);
    M2C_FIELD(arg0, s32*, 0x20) = var_a1;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    if (temp_v1 != 0) {
        temp_v0 += 0x10;
    } else {
        temp_v0 -= 0x10;
    }
    M2C_FIELD(arg0, s16*, 0xA) = temp_v0;
    M2C_FIELD(arg0, u8*, 0x16) = 6;
    M2C_FIELD(arg0, s32**, 0x68) = &D_800F3B48_ovl08;
    M2C_FIELD(arg0, s32**, 0x54) = &D_800F3B44_ovl08;
    M2C_FIELD(arg0, s32**, 0x50) = &D_800F3B44_ovl08;
    M2C_FIELD(arg0, s32**, 0x58) = &D_80074E40;
    M2C_FIELD(arg0, u8*, 0x60) = 2;
    M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE) + 3;
    set_animation(arg0, 8);
}

extern u8 D_8009A197;
s32 func_8004FC64(u8* a0);

void func_800EF780_ovl08(u8* a0) {
    s32 state;

    if (D_8009A197 == 0) {
        animate_object();
        move_object(a0);
    }
    if (func_800317B8(a0) != 0) {
        state = 2;
        goto store;
    }
    if (func_80031DD0(a0) < 0) {
        state = 2;
        goto store;
    }
    if (a0[0x70] == 0) {
        ((s32(*)())func_8002F8FC)(a0);
        if (a0[0x70] == 0) {
            goto check;
        }
    }
    func_8004FC64(a0);
    a0[4]++;
    return;
check:
    if (is_off_screen(a0, 0x20, 0x20) == 0) {
        func_8002D9EC(a0, 0x10, 0x10);
        return;
    }
    state = a0[4] + 1;
store:
    a0[4] = state;
}
