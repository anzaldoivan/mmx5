/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80052D6C.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D760(void*, void*); /* extern */
extern s8 D_800D1C1D;

void func_80056ADC(void* arg0) {
    M2C_FIELD(arg0, s8*, 0x14) = 0;
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    if ((M2C_FIELD(arg0, u8*, 2) & 0xF) == D_800D1C1D) {
        func_8002D760(arg0, arg0);
    }
}
