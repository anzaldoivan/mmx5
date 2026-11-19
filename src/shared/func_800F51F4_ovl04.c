/* Shared body (DK-5), from the banked draft of func_800F51F4_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"

extern void (*D_80101BB0_ovl04[])(u8*);

void DEDUP_NAME(u8* obj) {
    D_80101BB0_ovl04[(s8)obj[5]](obj);
    if (((s8*)obj)[3] != 0) {
        DEDUP_CALLEE(obj, 0x40, 0x40);
    }
}
