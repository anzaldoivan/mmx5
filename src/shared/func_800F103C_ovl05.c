/* Shared body (DK-5), from the banked draft of func_800F103C_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(s32 a0, s32 a1, void* a2, s32 a3, s32 a4);

void DEDUP_NAME(Obj800F103C* p) {
    if (--p->unk8C == 0) {
        p->unk8C = 7;
        if (p->unk15 == 0) {
            p->unkA += 0x10;
            DEDUP_CALLEE(2, 0, p, 1, 1);
            p->unkA -= 0x10;
        } else {
            p->unkA -= 0x10;
            DEDUP_CALLEE(2, 0, p, 1, 1);
            p->unkA += 0x10;
        }
    }
}
