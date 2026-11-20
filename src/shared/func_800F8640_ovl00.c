/* Shared body (DK-5), from the banked draft of func_800F8640_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"

extern void (*D_800FB50C_ovl00[])(u8*);

void DEDUP_NAME(u8* arg0) {
    D_800FB50C_ovl00[(signed char)arg0[6]](arg0);
    DEDUP_CALLEE(arg0, 0xFF, 0xFF);
}
