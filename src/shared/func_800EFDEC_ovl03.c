#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/title.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

/* Adapted from mmx6 @c1c892d src/shared/rock_15/func_800EA448.c, AGPL-3.0 (THIRD_PARTY.md). */
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK D_80074DA0;
extern M2C_UNK D_800F96CC_ovl03;
extern M2C_UNK D_800F96D0_ovl03;

void func_800EFDEC_ovl03(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x24) = 0xFFFF0000;
    M2C_FIELD(arg0, s32*, 0x2C) = 0x3000;
    M2C_FIELD(arg0, void**, 0x68) = &D_800F96CC_ovl03;
    M2C_FIELD(arg0, void**, 0x54) = &D_800F96D0_ovl03;
    M2C_FIELD(arg0, void**, 0x58) = &D_80074DA0;
    M2C_FIELD(arg0, void**, 0x50) = &D_800F96D0_ovl03;
    {
        // !FAKE: pins one to $5; gcc 2.7.2 allocates another register without it (byte mismatch)
        register s32 one asm("$5") = 1;
        M2C_FIELD(arg0, u8*, 0x3) = one;
        {
            // !FAKE: pins k to $3; gcc 2.7.2 allocates another register without it (byte mismatch)
            register s32 k asm("$3") = 5;
            M2C_FIELD(arg0, u8*, 0x60) = k;
        }
        M2C_FIELD(arg0, u8*, 0x5C) = one;
    }
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, u8*, 0x4) = (u8)(M2C_FIELD(arg0, u8*, 0x4) + 1);
    M2C_FIELD(arg0, u16*, 0x42) = (u16)(M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF);
    set_animation(arg0, 2);
}

extern u8 D_8009A197;

void func_800EFE78_ovl03(u8* a0) {
    if (D_8009A197 == 0) {
        animate_object();
        apply_object_motion(a0);
    }
    if (func_80031DD0(a0) < 0) {
        ((s32(*)())func_8004FD24)(a0);
        a0[4]++;
        return;
    }
    if (func_800317B8(a0) != 0) {
        ((s32(*)())func_8004FD24)(a0);
        a0[4] = 2;
        return;
    }
    if (a0[0x70] == 0) {
        ((s32(*)())func_8002F8FC)(a0);
        if (a0[0x70] == 0) {
            goto check;
        }
    }
    *(u16*)(a0 + 0xE) += 0x20;
    ((s32(*)())func_8004FD24)(a0);
    a0[4]++;
    return;
check:
    if (is_off_screen(a0, 0x20, 0x20) == 0) {
        func_8002D9EC(a0, 0x10, 0x10);
        return;
    }
    a0[4]++;
}
