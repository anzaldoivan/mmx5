/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80018948.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32

s8 func_80066D58(M2C_UNK, u8*);       /* extern */
s32 CdControl(M2C_UNK, M2C_UNK, u8*); /* extern */
extern u8 D_800A51A4;
extern s8 D_800E805E;
extern s32 D_800E8060;
extern u8 D_800E8088;
extern s16 D_800E8090;
extern s32 D_800E8094;

void func_80018040(void) {
    s32 temp_v0;

    temp_v0 = func_80066D58(1, 0);
    if ((temp_v0 == 2) && (D_800E8094 != 0) && (D_800A51A4 == 0) &&
        (CdControl(0x1B, 0, &D_800E8088) != 0)) {
        D_800E8090 = 0;
        D_800E8060 = temp_v0;
        if (D_800E8088 & 0x10) {
            D_800E805E = 1;
        }
    }
}
