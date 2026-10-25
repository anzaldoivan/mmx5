/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8003A268.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003CE64();      /* extern */
M2C_UNK func_8003EC00(void*); /* extern */

void func_80039A7C(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0xD5) > 0) {
        func_8003CE64();
        func_8003EC00(arg0);
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        M2C_FIELD(arg0, s8*, 0x67) = 1;
        M2C_FIELD(arg0, s8*, 5) = 0x12;
        M2C_FIELD(arg0, s8*, 6) = 1;
        M2C_FIELD(arg0, s8*, 0xD5) = (s8) - (s8)(u8)M2C_FIELD(arg0, s8*, 0xD5);
    }
}
