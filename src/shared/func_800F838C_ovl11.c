/* Shared body (DK-5), from the banked draft of func_800F838C_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* a0);
extern s16 D_8009A0AA;

void DEDUP_NAME(u8* a0) {
    if (*(s32*)(a0 + 0x20) < 0) {
        if (D_8009A0AA > *(s16*)(a0 + 0xA)) {
            a0[6]++;
        }
    } else if (D_8009A0AA < *(s16*)(a0 + 0xA)) {
        a0[6]++;
    }
    if (*(signed char*)(*(u8**)(a0 + 0x7C) + 4) == 2) {
        a0[6]++;
    }
    DEDUP_CALLEE(a0);
}
