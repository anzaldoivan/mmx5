#include "types.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EF510_ovl21(void* arg0) {
    void* temp_a1;

    temp_a1 = M2C_FIELD(arg0, void**, 0x5C);
    M2C_FIELD(arg0, s32*, 8) = M2C_FIELD(temp_a1, s32*, 0x18);
    M2C_FIELD(arg0, s32*, 0xC) = M2C_FIELD(temp_a1, s32*, 0x1C);
}
