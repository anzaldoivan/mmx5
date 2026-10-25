/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8004D074.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/quads/quad_07_ready_line.c:ready_line_move, AGPL-3.0; proven shared with X6 by exact signature 067862c5794d (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80052BA0(struct X4_QuadObj* arg0) {
    M2C_FIELD(arg0, s32*, 0x8) += M2C_FIELD(arg0, s32*, 0x38);
    M2C_FIELD(arg0, s32*, 0xC) += M2C_FIELD(arg0, s32*, 0x3C);
    M2C_FIELD(arg0, s32*, 0x38) += M2C_FIELD(arg0, s32*, 0x40);
    M2C_FIELD(arg0, s32*, 0x3C) += M2C_FIELD(arg0, s32*, 0x44);
}
