/* Shared body (DK-5), from the banked draft of func_800F84BC_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

void DEDUP_NAME(Obj800F84BC* p) {
    p->unk8C += 0x10000;
    p->unk90 -= 0x10000;
    // !FAKE: volatile read keeps the global load below the stores (C0194)
    if (!(*(volatile s32*)&D_8009A420_as_s32 & 1)) {
        p->unk8 = p->unk8C;
    } else {
        p->unk8 = p->unk90;
    }
    if (--p->unk95 == 0) {
        p->unk6++;
    }
}
