#include "types.h"

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8002130C.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800233D8(void* arg0) {
    void* temp_a1;

    temp_a1 = M2C_FIELD(arg0, void**, 0x50);
    M2C_FIELD(arg0, s32*, 8) = (s32)M2C_FIELD(temp_a1, s32*, 0x18);
    M2C_FIELD(arg0, s32*, 0xC) = (s32)M2C_FIELD(temp_a1, s32*, 0x1C);
}
#undef M2C_FIELD

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8002132C.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/afterimage.c:func_800AE88C, AGPL-3.0; proven shared with X6 by exact signature fb1027ecedab (see THIRD_PARTY.md). */

extern void (*D_800712E8[])(X4_Obj*, X4_Obj*);

void func_800233F8(X4_Obj* arg0, X4_Obj* arg1) {
    if (arg1->afterimage == 0) {
        arg0->on_screen = 0;
        arg0->state = 0;
        return;
    }

    D_800712E8[arg0->unk5](arg0, arg1);
}
