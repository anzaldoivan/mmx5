/* Shared body (DK-5), from the banked draft of func_800F0648_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"

void DEDUP_NAME(u8* obj) {
    D_1F80004C.bytes[0x86] = 0;
    DEDUP_CALLEE(obj, 6);
    obj[6]++;
}
