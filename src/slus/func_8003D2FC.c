/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8003D34C.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80030A0C();           /* extern */
s32 func_8003CB50(void*, s16); /* extern */

void func_8003D2FC(void* arg0) {
    if (func_80030A0C() == 0x24) {
        func_8003CB50(arg0, (s16)(M2C_FIELD(arg0, u16*, 0xE) & 0xFFF0));
    }
}
