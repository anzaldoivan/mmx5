/* Shared body (DK-5), from the banked draft of func_800FA734_ovl50 by tools/wave/gate.py rescan. */
#include "types.h"

void DEDUP_CALLEE(s32, s32, s32);

void DEDUP_NAME(Ovl45State* arg0) {
    if (arg0->unk4 == 0) {
        DEDUP_CALLEE(0x28, 0xFF, 0);
        arg0->unk1++;
    }
}
