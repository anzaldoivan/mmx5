#include "types.h"
#include "mmx5/globals.h"

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80048524.c, AGPL-3.0 (THIRD_PARTY.md). */
#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8004E25C(void* arg0) {
    M2C_FIELD(arg0, s8*, 3) = 0;
    if (D_8009A420_as_s32 & 0x10) {
        ((s32(*)())func_8002D89C)();
    }
}
#undef D_8009A420_as_s32
#undef M2C_FIELD

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80048560.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8004E298(void* arg0) {
    M2C_FIELD(arg0, s8*, 3) = 1;
    ((s32(*)())func_8002D89C)();
}
