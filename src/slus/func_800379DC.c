/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80037DC4.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017248(void*); /* extern */
s32 func_80039ECC(void*);     /* extern */
M2C_UNK func_8003CD08();      /* extern */

void func_800379DC(void* arg0) {
    func_8003CD08();
    if (func_80039ECC(arg0) == 0) {
        if (M2C_FIELD(arg0, s8*, 0xD0) == 0) {
            M2C_FIELD(arg0, s8*, 5) = 2;
            M2C_FIELD(arg0, s8*, 6) = 0;
            return;
        }
        func_80017248(arg0);
    }
}
