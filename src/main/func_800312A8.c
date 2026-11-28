/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_800309F8.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/1CF60.c:func_8002D32C, AGPL-3.0; proven shared with X6 by exact signature 42673ebd7e4e (see THIRD_PARTY.md). */
#include "types.h"
extern int func_80031398();
extern s16 D_800E930A;
extern s16 D_800E9316;
u8 func_80030AE4(X4_Obj*, s16, s16);

s32 func_800312A8(X4_Obj* arg0, s16 arg1, s32 arg2) {
    if (func_80031398(arg0, func_80030AE4(arg0, D_800E9316, arg1), arg2) == 0) {
        if (func_80031398(arg0,
                          func_80030AE4(arg0, D_800E9316 - D_800E930A, arg1),
                          arg2) == 0) {
            if (func_80031398(
                    arg0,
                    func_80030AE4(arg0, D_800E9316 + D_800E930A - 1, arg1),
                    arg2) == 0) {
                return 0;
            }
        }
    }
    return -1;
}
