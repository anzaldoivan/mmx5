/* Shared body (DK-5), from the banked draft of func_800FA408_ovl50 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_800D1F3C;
extern void DEDUP_CALLEE(s32, s32, s32);

void DEDUP_NAME(u8* arg0) {
    if (D_800D1F3C == 2) {
        DEDUP_CALLEE(0x25, 0xFF, 0);
        arg0[1]++;
    }
}
