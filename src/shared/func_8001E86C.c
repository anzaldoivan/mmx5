/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80041AB8.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

extern void (*D_80070EC0[])(s8*);

void func_8001E86C(s8* arg0) {
    D_80070EC0[arg0[1]](arg0);
}
