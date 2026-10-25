/* Adapted from mmx6 @c1c892d src/shared/rock_00/func_801EC240.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002DF54(void*);          /* extern */
s32 func_80039AE0(void*);              /* extern */
M2C_UNK func_8003F294(void*, M2C_UNK); /* extern */
M2C_UNK func_8003F2D8(void*, M2C_UNK); /* extern */
s32 func_80040B6C();                   /* extern */
s32 func_80040BBC(void*);              /* extern */

void func_80040A50(void* arg0) {
    s32 temp_v0;
    s8 var_v0;

    if ((func_80040B6C() == 0) && (func_80039AE0(arg0) == 0)) {
        temp_v0 = func_80040BBC(arg0);
        if (temp_v0 != 0) {
            if (temp_v0 > 0) {
                func_8003F294(arg0, 0x17);
                var_v0 = 3;
                goto block_7; // !FAKE: control flow kept from the mmx6 twin
            }
            func_8002DF54(arg0);
            func_8003F2D8(arg0, 0x19);
            return;
        }
        func_8003F294(arg0, 0x1A);
        var_v0 = 6;
    block_7:
        M2C_FIELD(arg0, s8*, 6) = var_v0;
    }
}
