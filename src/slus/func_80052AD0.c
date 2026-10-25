/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8004CFA4.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/quads/quad_07_ready_line.c:ready_line_init, AGPL-3.0; proven shared with X6 by exact signature 2100185f1445 (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80052AD0(struct X4_QuadObj* arg0) {
    M2C_FIELD(arg0, s8*, 0x0) |= 0x92;
    if (arg0->unk2 == 0) {
        M2C_FIELD(arg0, s8*, 0x36) = 0x10;
    } else {
        M2C_FIELD(arg0, s8*, 0x36) = 0x13;
    }
    M2C_FIELD(arg0, u16*, 0x34) = 5;
    arg0->state = 1;
    M2C_FIELD(arg0, s8*, 0x37) = -1;
    M2C_FIELD(arg0, s32*, 0x8) = 0;
    M2C_FIELD(arg0, s32*, 0xC) = 0;
    arg0->vertices[0].x.w = 0;
    arg0->vertices[0].y.w = 0;
    arg0->vertices[1].x.w = 0;
    arg0->vertices[1].y.w = 0;
    arg0->vertices[2].x.w = 0;
    arg0->vertices[2].y.w = 0;
    arg0->vertices[3].x.w = 0;
    arg0->vertices[3].y.w = 0;
}
