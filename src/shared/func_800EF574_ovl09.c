/* Shared body (DK-5), from the banked draft of func_800EF574_ovl09 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8002992C.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32

M2C_UNK func_8002DF54(s32); /* extern */
M2C_UNK func_80017248();    /* extern */

void DEDUP_NAME(s32 arg0) {
    func_80017248();
    func_8002DF54(arg0);
}
