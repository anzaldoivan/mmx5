/* Shared body (DK-5), from the banked draft of func_800FC8A0_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"

void DEDUP_CALLEE(void* self);

void DEDUP_NAME(u8* self) {
    if (--*(s16*)(self + 0x7C) == -1) {
        DEDUP_CALLEE(self);
    }
}
