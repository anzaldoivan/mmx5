/* Shared body (DK-5), from the banked draft of func_800EFD94_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern void (*D_800F203C_ovl12[])(u8*);

void DEDUP_NAME(u8* arg0) {
    D_800F203C_ovl12[(signed char)arg0[6]](arg0);
    animate_object(arg0);
    apply_object_motion(arg0);
    func_8002D9EC(arg0, 0xFF, 0xFF);
}
