/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8002D3B4.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/object_motion.c:set_velocity_from_angle, AGPL-3.0; proven shared with X6 by exact signature e92a2af1038e (see THIRD_PARTY.md). */
#include "types.h"
extern s32 D_80073164[];
extern s32 D_80073188[];

void func_8002E058(X4_Obj* arg0, s32 arg1) {
    u8 angle;
    s16 var_a2, var_v0;
    s16 var_v1;

    angle = arg1;
    if (angle < 0x10) {
        var_a2 = 1;
        if (angle < 8) {
            var_v1 = 8 - angle;
            var_v0 = 1;
        } else {
            var_v1 = angle - 8;
            var_v0 = -1;
        }
    } else {
        var_a2 = -1;
        if (angle < 0x18) {
            var_v1 = 0x18 - angle;
            var_v0 = -1;
        } else {
            var_v1 = angle - 0x18;
            var_v0 = 1;
        }
    }
    arg0->x_vel.val = D_80073164[var_v1] * var_v0;
    arg0->y_vel.val = D_80073188[var_v1] * var_a2;
}
