/* Shared body (DK-5), from the banked draft of func_800FA9B8_ovl58 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(s32, s32, void*);
extern u8 D_80091C44;

void DEDUP_NAME(UnkObj* arg0) {
    if (D_80091C44 == 0) {
        arg0->unk4 = 0;
        arg0->unk6 = 0;
        arg0->unk1++;
        DEDUP_CALLEE(2, 0x58, 0);
    }
}
