/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80018838.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32

s8 func_80066D58(M2C_UNK, u8*);       /* extern */
s32 CdControl(M2C_UNK, M2C_UNK, u8*); /* extern */
extern s8 D_800D1F3C;
extern s32 D_800E8060;
extern u8 D_800E8088;

void func_80017F30(void) {
    s8 temp_v0;

    temp_v0 = func_80066D58(1, &D_800E8088);
    if ((temp_v0 == 2) && !(D_800E8088 & 0x40) &&
        (CdControl(0x1B, 0, &D_800E8088) != 0)) {
        D_800D1F3C = temp_v0;
        D_800E8060 = (s32)temp_v0;
    }
}
