/* Shared body (DK-5), from the banked draft of func_800F724C_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"

extern void (*D_800FA514_ovl29[])(u8*);

void DEDUP_NAME(u8* arg0) {
    D_800FA514_ovl29[(signed char)arg0[6]](arg0);
    DEDUP_CALLEE(arg0, 0x30, 0x30);
}
