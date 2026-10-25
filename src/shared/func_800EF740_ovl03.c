/* Shared body (DK-5), from the banked draft of func_800EF740_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(Obj3DD4*, s32);
extern s32 D_800F95AC_ovl03[];

void DEDUP_NAME(Obj3DD4* o) {
    DEDUP_CALLEE(o, 3);
    o->unk20 = D_800F95AC_ovl03[(o->unk15 >> 6) & 1];
    o->unk24 = 0x5000;
    o->unk6++;
}
