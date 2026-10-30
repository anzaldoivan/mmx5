/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8002974C.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32

M2C_UNK func_8002A960(s32);                 /* extern */
M2C_UNK func_8002A980();                    /* extern */
void func_8002A9A0(X4_BackgroundObj* arg0); /* extern */

void func_8002A8D4(s32 arg0) {
    func_8002A980();
    func_8002A960(arg0);
    func_8002A9A0(arg0);
}
