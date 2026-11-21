#include "types.h"

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8002D454.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/object_motion.c:func_8002B9F0, AGPL-3.0; proven shared with X6 by exact signature 5e8e8871519a (see THIRD_PARTY.md). */
extern s32 D_80073164[];
extern s32 D_80073188[];

void func_8002E0F8(s32* arg0, s32* arg1, u8 arg2) {
    s16 var_a3, var_v0;
    s16 var_v1;

    if (arg2 < 0x10) {
        var_a3 = 1;
        if (arg2 < 8) {
            var_v1 = 8 - arg2;
            var_v0 = 1;
        } else {
            var_v1 = arg2 - 8;
            var_v0 = -1;
        }
    } else {
        var_a3 = -1;
        if (arg2 < 0x18) {
            var_v1 = 0x18 - arg2;
            var_v0 = -1;
        } else {
            var_v1 = arg2 - 0x18;
            var_v0 = 1;
        }
    }
    *arg0 = D_80073164[var_v1] * var_v0;
    *arg1 = D_80073188[var_v1] * var_a3;
}

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8002D4F4.c, AGPL-3.0 (THIRD_PARTY.md). */

extern u16 D_8009A120;

s32 func_8002E198(void) {
    s32 var_v0;

    var_v0 = (D_8009A120 & 0xF) != 0;
    if (D_8009A120 & 0x1B0) {
        var_v0 += 1;
    }
    return var_v0;
}

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8002D51C.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/object_motion.c:get_layout_screen, AGPL-3.0; proven shared with X6 by exact signature b57657e8090d (see THIRD_PARTY.md). */
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
