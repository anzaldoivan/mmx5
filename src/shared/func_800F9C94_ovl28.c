/* Shared body (DK-5), from the banked draft of func_800F9C94_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern void (*D_800FE71C_ovl28[])(u8*);

void DEDUP_NAME(u8* arg0) {
    D_800FE71C_ovl28[(signed char)arg0[6]](arg0);
    animate_object(arg0);
    apply_object_motion(arg0);
    func_8002D9EC(arg0, 0x30, 0x30);
}
