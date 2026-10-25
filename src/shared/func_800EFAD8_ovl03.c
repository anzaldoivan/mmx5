/* Shared body (DK-5), from the banked draft of func_800EFAD8_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(s32, s32, void*);
extern s8 D_800D1C26;

void DEDUP_NAME(Obj* arg0) {
    if (D_800D1C26 != 0) {
        arg0->timer = 0x1E;
        arg0->step++;
        DEDUP_CALLEE(2, 0xE, arg0);
    }
}
