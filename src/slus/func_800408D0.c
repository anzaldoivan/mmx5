/* Adapted from mmx6 @c1c892d src/shared/rock_00/func_801EC0C0.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32

s32 func_80039AE0(void*);                        /* extern */
M2C_UNK func_8003F2D8(void*, M2C_UNK);           /* extern */
s32 func_80040B6C();                             /* extern */
s32 func_80040BBC(void*);                        /* extern */
void func_80040C88(X4_Obj* self, s32 direction); /* extern */

void func_800408D0(s32 arg0) {
    s32 temp_v0;

    if ((func_80040B6C() == 0) && (func_80039AE0(arg0) == 0)) {
        temp_v0 = func_80040BBC(arg0);
        if (temp_v0 != 0) {
            func_80040C88(arg0, temp_v0);
            return;
        }
        func_8003F2D8(arg0, 0x16);
    }
}
