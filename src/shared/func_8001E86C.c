/* Shared body (DK-5), from the banked draft of func_8001E86C by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80041AB8.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

extern void (*D_80070EC0[])(s8*);

void DEDUP_NAME(s8* arg0) {
    D_80070EC0[arg0[1]](arg0);
}
