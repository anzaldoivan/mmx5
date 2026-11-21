#include "types.h"

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8004C744.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80032CEC(); /* extern; was M2C_UNK (W15 regate of 328B0) */

void func_80052270(void* arg0) {
    M2C_FIELD(arg0, s16*, 0x34) = 3;
    M2C_FIELD(arg0, s32*, 0x38) = 0x40000;
    M2C_FIELD(arg0, s8*, 0x36) = 0;
    M2C_FIELD(arg0, s8*, 0x37) = 0;
    M2C_FIELD(arg0, s32*, 0x14) = 0;
    M2C_FIELD(arg0, s32*, 0x18) = 0;
    M2C_FIELD(arg0, s32*, 0x1C) = 0;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, s32*, 0x30) = 0;
    M2C_FIELD(arg0, u8*, 0) = (u8)(M2C_FIELD(arg0, u8*, 0) | 0x82);
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    func_80032CEC();
}
#undef M2C_UNK
#undef M2C_FIELD

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8004C7B0.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/quads/quad_08_flash_band.c:flash_band_widen, AGPL-3.0; proven shared with X6 by exact signature f8c67d3d4451 (see THIRD_PARTY.md). */
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define FIXED(x) ((s32)((x) * 0x10000))

#define M2C_UNK s32
void func_80032CEC(); /* was M2C_UNK (W15 regate of 328B0) */
void func_800522DC(struct X4_QuadObj* arg0) {
    arg0->vertices[0].x.w += M2C_FIELD(arg0, s32*, 0x38);
    arg0->vertices[3].x.w -= M2C_FIELD(arg0, s32*, 0x38);
    M2C_FIELD(arg0, s32*, 0x38) += FIXED(4);
    func_80032CEC(arg0);
    if (M2C_FIELD(arg0, s16*, 0x16) > 0x14A) {
        arg0->state++;
    }
}
