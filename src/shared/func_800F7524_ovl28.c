/* Shared body (DK-5), from the banked draft of func_800F7524_ovl28 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8002132C.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

extern void (*D_800FE36C_ovl28[])(ObjFAF30*, ObjFAF30*);

void DEDUP_NAME(ObjFAF30* arg0, ObjFAF30* arg1) {
    if (arg1->unk9A == 0) {
        arg0->unk3 = 0;
        arg0->unk4 = 0;
        return;
    }

    D_800FE36C_ovl28[arg0->unk5](arg0, arg1);
}
