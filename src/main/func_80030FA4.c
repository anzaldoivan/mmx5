/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_800306F4.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/1CF60.c:func_8002CC98, AGPL-3.0; proven shared with X6 by exact signature 8fa4d2d2edd1 (see THIRD_PARTY.md). */
#include "types.h"
extern s16 D_800E930A;
extern s16 D_800E930C;
extern s16 D_800E9316;
extern s16 D_800E9318;
u8 func_80030BB4(X4_Obj*, s16, s16);
s32 func_8003107C(X4_Obj* arg0, u8 arg1);

void func_80030FA4(X4_Obj* arg0) {
    s16 temp_v0;

    temp_v0 = D_800E9318 - D_800E930C;
    if ((func_8003107C(arg0, func_80030BB4(arg0, D_800E9316, temp_v0)) == 0) &&
        (func_8003107C(arg0, func_80030BB4(arg0, D_800E9316 - D_800E930A,
                                           temp_v0)) == 0)) {
        func_8003107C(
            arg0, func_80030BB4(arg0, D_800E9316 + D_800E930A - 1, temp_v0));
    }
}
