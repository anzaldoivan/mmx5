/* Shared body (DK-5), from the banked draft of func_800F060C_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern void (*D_800FC6A4_ovl01[])(u8*);
void DEDUP_CALLEE(u8*);

void DEDUP_NAME(u8* arg0) {
    D_800FC6A4_ovl01[(signed char)arg0[6]](arg0);
    DEDUP_CALLEE(arg0);
}
