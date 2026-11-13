/* Dedup member (tools/dedup/propagate.py): cyclic rename, body inlined. */
#include "types.h"

#define DEDUP_NAME func_80030E60

// dedup-inline ../shared/func_80030E1C.c
// dedup-rename func_8003049C func_800311CC
// dedup-rename func_800311CC func_8003049C

/* Shared body (DK-5), from the banked draft of func_80030E1C by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8003056C.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32

s32 func_800311CC(X4_Obj* arg0); /* extern */
M2C_UNK func_80030EA4(s32);      /* extern */
s32 func_8003049C();             /* extern */

void DEDUP_NAME(s32 arg0) {
    if ((func_8003049C() != 0) && (func_800311CC(arg0) != 0)) {
        func_80030EA4(arg0);
    }
}
