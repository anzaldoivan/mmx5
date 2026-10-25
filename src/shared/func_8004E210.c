/* Shared body (DK-5), from the banked draft of func_8004E210 by tools/wave/gate.py rescan. */
#include "types.h"

extern void (*D_8007B56C[])(u8*);
void DEDUP_CALLEE(u8*);

void DEDUP_NAME(u8* arg0) {
    D_8007B56C[(signed char)arg0[5]](arg0);
    DEDUP_CALLEE(arg0);
}
