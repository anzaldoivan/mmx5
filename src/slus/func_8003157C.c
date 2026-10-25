#include "types.h"

extern u8 func_80030AE4(X4_Obj*, s16, s16);
extern s16 D_800E931E;
extern s16 D_800E9328[];

u8 func_8003157C(X4_Obj* obj, s16 x, s16 y) {
    s32 i;

    for (i = 0; i < D_800E931E; i++) {
        if (x >= D_800E9328[i * 4 + 0] && D_800E9328[i * 4 + 1] >= x &&
            y >= D_800E9328[i * 4 + 2] && D_800E9328[i * 4 + 3] >= y) {
            return 0x38;
        }
    }
    return func_80030AE4(obj, x, y);
}
