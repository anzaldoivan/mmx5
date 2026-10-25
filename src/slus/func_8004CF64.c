/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_800466C4.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8004CF64(void* arg0) {
    void* temp_a1;

    temp_a1 = M2C_FIELD(arg0, void**, 0x7C);
    if (M2C_FIELD(temp_a1, s8*, 4) == 1) {
        M2C_FIELD(arg0, u16*, 0xA) = (u16)M2C_FIELD(temp_a1, u16*, 0xA);
        M2C_FIELD(arg0, u16*, 0xE) = (u16)M2C_FIELD(temp_a1, u16*, 0xE);
        if (M2C_FIELD(arg0, s8*, 2) != 0) {
            goto block_3; // !FAKE: control flow kept from the mmx6 twin
        }
    } else {
    block_3:
        M2C_FIELD(arg0, s8*, 4) = 2;
    }
}
