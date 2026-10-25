/* Adapted from mmx6 @c1c892d src/shared/rock_00/func_801EC4C0.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002DED4(void*); /* extern */
M2C_UNK func_80040E98();      /* extern */

void func_80040CD0(void* arg0) {
    func_80040E98();
    if (M2C_FIELD(arg0, s8*, 0x45) & 0x80) {
        M2C_FIELD(arg0, s8*, 0x45) = 0;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        return;
    }
    func_8002DED4(arg0);
}
