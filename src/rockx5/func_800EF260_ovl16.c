/* Adapted from mmx6 @c1c892d src/shared/rock_12/func_800EA2A0.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EF260_ovl16(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        M2C_FIELD(M2C_FIELD(arg0, void**, 0x38), u8*, 0x36) =
            (u8)M2C_FIELD(arg0, u8*, 0x36);
    }
}
