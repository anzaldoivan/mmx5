/* Shared body (DK-5), from the banked draft of func_800F1D84_ovl26 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void DEDUP_CALLEE(Ent1D84*, s32);
extern s32 D_8009A1B8;

void DEDUP_NAME(Ent1D84* o) {
    if (D_1F80004C.scr84->unk86 == 0) {
        DEDUP_CALLEE(o, 3);
    } else {
        DEDUP_CALLEE(o, 3);
    }
    D_1F80004C.scr84->unk80 = o->unk8;
    D_1F80004C.scr84->unk86++;
    if (D_1F80004C.scr84->unk84 == 0) {
        o->unk15 = 0x40;
        o->unk24 = 0;
        o->unk20 = D_8009A1B8;
    } else {
        o->unk15 = 0;
        o->unk24 = 0;
        o->unk20 = -D_8009A1B8;
    }
    o->unk6++;
}
