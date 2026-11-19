/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80037DC4.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003CD08(); /* extern */

void update_control_lock(void* arg0) {
    func_8003CD08();
    if (func_80039ECC(arg0) == 0) {
        if (M2C_FIELD(arg0, s8*, 0xD0) == 0) {
            M2C_FIELD(arg0, s8*, 5) = 2;
            M2C_FIELD(arg0, s8*, 6) = 0;
            return;
        }
        animate_object(arg0);
    }
}
