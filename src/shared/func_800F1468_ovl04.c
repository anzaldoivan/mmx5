/* Shared body (DK-5), from the banked draft of func_800F1468_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

void DEDUP_CALLEE(u8* arg0, s32 arg1);

void DEDUP_NAME(u8* arg0) {
    if (--*(s16*)(arg0 + 0x7C) == -1) {
        *(s16*)(arg0 + 0x7C) = 0x78;
        if ((*(u16*)(arg0 + 0x7E) ^= 1) == 0) {
            DEDUP_CALLEE(arg0, 0x10);
            DEDUP_CALLEE(arg0, 0x11);
            DEDUP_CALLEE(arg0, 0x12);
        } else {
            DEDUP_CALLEE(arg0, 0x20);
            DEDUP_CALLEE(arg0, 0x21);
            DEDUP_CALLEE(arg0, 0x22);
        }
    }
}
