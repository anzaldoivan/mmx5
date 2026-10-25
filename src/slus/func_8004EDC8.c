/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80048E14.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D6FC();    /* extern */
s32 func_8002D89C(X4_Obj*); /* extern */
extern u8 D_8009A427;
extern s8 D_800D1C01;

void func_8004EDC8(void* arg0) {
    ((s32(*)())func_8002D89C)();
    if (M2C_FIELD(arg0, s8*, 0x54) != D_800D1C01) {
        func_8002D6FC(arg0);
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x55) != D_8009A427) {
        func_8002D6FC(arg0);
    }
}
