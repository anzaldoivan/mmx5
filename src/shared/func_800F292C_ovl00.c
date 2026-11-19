/* Shared body (DK-5), from the banked draft of func_800F292C_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj, 6);
    D_1F80004C.bytes[0x84] = 3;
    obj[6]++;
}
