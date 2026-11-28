/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8002F840.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/1CF60.c:func_8002CDD4, AGPL-3.0; proven shared with X6 by exact signature 35842cc5ea2e (see THIRD_PARTY.md). */
#include "types.h"
extern int func_80031168();
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern s16 D_800E930A;
extern s16 D_800E930C;
extern s16 D_800E9316;
extern s16 D_800E9318;
s32 func_8003028C(X4_Obj*, u8, s16, s16);
u8 func_80030BB4(X4_Obj*, s16, s16);

void func_800300F0(X4_Obj* arg0) {
    u8 temp_s3;
    u8 temp_s4;
    u8 temp_s5;
    u8 temp_v0_4;
    s32 var_s0;
    s16 temp_v0 = D_800E9318 + D_800E930C;

    temp_s3 = func_80030BB4(arg0, D_800E9316 - D_800E930A, temp_v0);
    temp_s4 = func_80030BB4(arg0, D_800E9316 + D_800E930A - 1, temp_v0);
    temp_s5 = func_80030BB4(arg0, D_800E9316, temp_v0);

    if (func_8003028C(arg0, temp_s5, D_800E9316, temp_v0) == 0) {
        if (M2C_FIELD(arg0, s8*, 0x67) == 0) {
            var_s0 = 0;
            if (temp_s3 > 0 && temp_s3 < 0x20) {
                var_s0 = 1;
            }
            if (temp_s4 > 0 && temp_s4 < 0x20) {
                var_s0 = 1;
            }

            temp_v0_4 = func_80030BB4(arg0, D_800E9316, (temp_v0 + 0x10));
            if (temp_v0_4 > 0 && temp_v0_4 < 0x20) {
                var_s0 = 1;
            }

            if (var_s0) {
                arg0->y_pos.i.hi += 0x10;
                if (func_8003028C(arg0, temp_v0_4, D_800E9316,
                                  temp_v0 + 0x10)) {
                    return;
                }
            }
        }

        if (func_80031168(arg0, temp_s3, temp_v0) == 0) {
            func_80031168(arg0, temp_s4, temp_v0);
        }
    }
}
