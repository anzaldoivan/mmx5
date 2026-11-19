/* Adapted from mmx6 @c1c892d src/shared/rock_20/func_800EECD8.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_80091C44;

void func_800F05FC_ovl24(void* arg0) {
    if (D_80091C44 == 0) {
        M2C_FIELD(arg0, u8*, 2) = (u8)(M2C_FIELD(arg0, u8*, 2) + 1);
    }
}
