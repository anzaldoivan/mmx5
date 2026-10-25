/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80018A90.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32

s8 func_80066D58(M2C_UNK, u8*);       /* extern */
s32 CdControl(M2C_UNK, M2C_UNK, u8*); /* extern */
s32 CdControlF(M2C_UNK, M2C_UNK*);    /* extern */
extern M2C_UNK D_800E804C;
extern s32 D_800E8060;
extern s32 D_800E8094;
extern u8 D_800E80A8;

void func_80018188(void) {
    s32 var_v0;

    if (func_80066D58(1, 0) == 2) {
        if (D_800E80A8 == 0) {
            var_v0 = CdControl(0x15, &D_800E804C, 0);
        } else {
            var_v0 = CdControlF(0x15, &D_800E804C);
        }
        if (var_v0 != 0) {
            D_800E8060 = 1;
        }
        D_800E8094 = 2;
    }
}
