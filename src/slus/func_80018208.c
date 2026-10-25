/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80018B10.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32

s8 func_80066D58(M2C_UNK, u8*);       /* extern */
s32 CdControl(M2C_UNK, M2C_UNK, u8*); /* extern */
extern s32 D_800E8060;
extern M2C_UNK D_800E80AC;

void func_80018208(void) {
    if ((func_80066D58(1, 0) == 2) && (CdControl(0xD, &D_800E80AC, 0) != 0)) {
        D_800E8060 = 5;
    }
}
