/* Shared body (DK-5), from the banked draft of func_800F0E9C_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void DEDUP_CALLEE(Obj0E9C*, s32);

void DEDUP_NAME(Obj0E9C* arg0) {
    arg0->unk67 = 0;
    arg0->unk6++;
    if ((arg0->unk2 & 0xF) == 2) {
        arg0->unk20 = 0;
    } else {
        s32 v = -0x40000;
        if (arg0->unk15 != 0) {
            v = 0x40000;
        }
        arg0->unk20 = v;
    }
    arg0->unk28 = 0;
    arg0->unk24 = 0;
    arg0->unk2C = 0;
    DEDUP_CALLEE(arg0, 0);
    D_1F80004C.ctx0f18->unk80 = 0x3C;
}
