/* Shared body (DK-5), from the banked draft of func_800F2A6C_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj, 0x10);
    D_1F80004C.bytes[0x8A] = 2;
    obj[6]++;
}
