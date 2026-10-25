/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8002D454.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/object_motion.c:func_8002B9F0, AGPL-3.0; proven shared with X6 by exact signature 5e8e8871519a (see THIRD_PARTY.md). */
#include "types.h"
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
