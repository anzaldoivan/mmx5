/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80021380.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/125BC.c:func_80021DBC, AGPL-3.0; proven shared with X6 by exact signature adb625a87261 (see THIRD_PARTY.md). */
#include "types.h"
extern Ovl50Pos D_800712F4[16];

void func_8002344C(s16* arg0, s16* arg1, s32 arg2) {
    Ovl50Pos* matrix;
    s16 x;
    s16 y;
    s32 product0;
    s32 product1;
    s32 product2;
    s32 product3;

    matrix = &D_800712F4[arg2 & 0xFF];
    x = *arg0;
    y = *arg1;
    product0 = x * matrix->unk0;
    product1 = y * matrix->unk2;
    product2 = x * matrix->unk4;
    product3 = y * matrix->unk6;
    *arg0 = (product0 >> 8) + (product1 >> 8);
    *arg1 = (product2 >> 8) + (product3 >> 8);
}
