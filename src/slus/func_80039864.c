/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80039F78.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80039864(void* arg0) {
    s8 temp_v0;
    u16 temp_v0_2;

    M2C_FIELD(arg0, s8*, 0x87) = 0;
    if ((M2C_FIELD(arg0, s8*, 0xD3) == 0) &&
        (temp_v0 = M2C_FIELD(arg0, s8*, 5), (temp_v0 != 0)) && (temp_v0 != 1)) {
        if (M2C_FIELD(arg0, s8*, 0x88) == 0) {
            temp_v0_2 = M2C_FIELD(arg0, u16*, 0x80) & 3;
            M2C_FIELD(arg0, u16*, 0x82) = temp_v0_2;
            if (temp_v0_2 != 0) {
                M2C_FIELD(arg0, s8*, 0x88) = 0xC;
            }
        } else {
            M2C_FIELD(arg0, s8*, 0x88) =
                (s8)((u8)M2C_FIELD(arg0, s8*, 0x88) - 1);
            if (M2C_FIELD(arg0, u16*, 0x80) & M2C_FIELD(arg0, u16*, 0x82)) {
                M2C_FIELD(arg0, s8*, 0x87) = 1;
                M2C_FIELD(arg0, s8*, 0x88) = 0;
            }
        }
    }
}
