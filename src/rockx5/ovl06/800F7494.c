#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

/* Adapted from mmx6 @c1c892d src/shared/rock_09/func_800EC6C4.c, AGPL-3.0 (THIRD_PARTY.md). */
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_800FF050_ovl06[];
extern ObjFAFFC D_800FF040_ovl06;

void func_800F7494_ovl06(void* arg0) {
    // !FAKE: pins tbl to $3; gcc 2.7.2 allocates another register without it (byte mismatch)
    register s32 tbl asm("$3");
    // !FAKE: pins v to $4; gcc 2.7.2 allocates another register without it (byte mismatch)
    register s32 v asm("$4");

    set_animation(arg0, 3);
    tbl = (s32)(D_800FF050_ovl06);
    v = *(s32*)((M2C_FIELD(arg0, u8*, 0x15) >> 4 & 4) + tbl);
    {
        // !FAKE: pins a to $2; gcc 2.7.2 allocates another register without it (byte mismatch)
        register void* a asm("$2") = &D_800FF040_ovl06;
        M2C_FIELD(arg0, void**, 0x50) = a;
    }
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x88) = 1;
    {
        // !FAKE: pins b to $3; gcc 2.7.2 allocates another register without it (byte mismatch)
        register s32 b asm("$3") = M2C_FIELD(arg0, u8*, 0x6);
        M2C_FIELD(arg0, u8*, 0x6) = b + 1;
    }
    M2C_FIELD(arg0, s32*, 0x20) = v;
}
#undef M2C_FIELD

#define func_800EF574_ovl09 func_800F7500_ovl06
#include "shared/func_800EF574_ovl09.c"
#undef func_800EF574_ovl09
