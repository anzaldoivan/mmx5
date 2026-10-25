/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8002D51C.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/object_motion.c:get_layout_screen, AGPL-3.0; proven shared with X6 by exact signature b57657e8090d (see THIRD_PARTY.md). */
#include "types.h"
#define SP(offset) (0x1F800000 + (offset))
#define SP_BG_TILEMAP (*(u8**)SP(0x004))
extern X4_BackgroundObj D_8009A1F8[3];
extern u8 D_800D1DBC;
extern u16 D_80091D58;

s16 func_8002E1C0(s16 arg0, s16 arg1, s16 arg2) {
    X4_BackgroundObj* temp_v1 = &D_8009A1F8[arg0];
    s16 var_x, var_y;
    s16 temp;

    var_x = (temp_v1->x_pos.i.hi + arg1) / 256;
    var_y = (temp_v1->y_pos.i.hi + arg2) / 256;
    temp = var_x + (arg0 * D_80091D58 + D_800D1DBC * var_y);

    return SP_BG_TILEMAP[temp];
}
