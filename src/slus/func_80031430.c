/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80030B80.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/1CF60.c:func_8002D5E4, AGPL-3.0; proven shared with X6 by exact signature ca45eff14472 (see THIRD_PARTY.md). */
#include "types.h"
extern s16 D_800E930C;
extern s16 D_800E9318;
u8 func_80030AE4(X4_Obj*, s16, s16);
s32 func_80031508(X4_Obj* arg0, u8 arg1);

s32 func_80031430(X4_Obj* arg0, s16 arg1) {
    if (func_80031508(
            arg0, func_80030AE4(arg0, arg1, D_800E9318 - D_800E930C)) == 0) {
        if (func_80031508(arg0, func_80030AE4(arg0, arg1, D_800E9318)) == 0) {
            if (func_80031508(
                    arg0, func_80030AE4(arg0, arg1,
                                        D_800E9318 + D_800E930C - 1)) == 0) {
                return 0;
            }
        }
    }
    return -1;
}
