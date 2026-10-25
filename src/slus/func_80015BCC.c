/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80016570.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32

s32 CdControlB(M2C_UNK, M2C_UNK, u8*); /* extern */

u8 func_80015BCC(void) {
    u8 sp10;

    do {

    } while (CdControlB(1, 0, &sp10) == 0);
    return sp10;
}
