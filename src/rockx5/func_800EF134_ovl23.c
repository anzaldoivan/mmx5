/* Adapted from mmx6 @c1c892d src/shared/rock_19/func_800EA000.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017248(); /* extern */
extern s8 D_800D1C44;

void func_800EF134_ovl23(void* arg0) {
    if (D_800D1C44 == 0) {
        M2C_FIELD(arg0, s8*, 3) = 1;
    } else {
        M2C_FIELD(arg0, s8*, 3) = 0;
    }
    func_80017248();
}
