/* Shared body (DK-5), from the banked draft of func_800F0120_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern void (*D_800F9748_ovl11[])(u8*);
extern s32 DEDUP_CALLEE(u8*);

void DEDUP_NAME(u8* arg0) {
    *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 0x8);
    *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0xC);
    D_800F9748_ovl11[(signed char)arg0[4]](arg0);
    if (*(s8*)(arg0 + 2) == 0) {
        DEDUP_CALLEE(arg0);
    }
}
