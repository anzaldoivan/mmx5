/* Shared body (DK-5), from the banked draft of func_800EECC0_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern void (*D_800F9570_ovl03[])(u8*);
void DEDUP_CALLEE(u8*);

void DEDUP_NAME(u8* arg0) {
    D_800F9570_ovl03[(signed char)arg0[4]](arg0);
    DEDUP_CALLEE(arg0);
}
