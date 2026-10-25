/* Adapted from mmx6 @c1c892d src/shared/rock_20/func_800EF674.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_8009A424[];
#define D_8009A424 (*(s8*)&D_8009A424)

void func_800F07C4_ovl24(void* arg0) {
    if (D_8009A424 == 0) {
        M2C_FIELD(arg0, s8*, 2) = 1;
    }
}
#undef D_8009A424
