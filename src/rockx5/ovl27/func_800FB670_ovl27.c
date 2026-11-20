/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80041AB8.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

extern void (*D_800FDBB8_ovl27[])(s8*);

void func_800FB670_ovl27(s8* arg0) {
    D_800FDBB8_ovl27[arg0[7]](arg0);
}
