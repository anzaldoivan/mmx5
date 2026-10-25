/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80041AB8.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

extern void (*D_800EF2E4_ovl16[])(s8*);

void func_800EEEFC_ovl16(s8* arg0) {
    D_800EF2E4_ovl16[arg0[0x1D]](arg0);
}
