/* Shared body (DK-5), from the banked draft of func_800FC85C_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj, 4);
    D_1F80004C.bytes[0x8E] = 1;
    obj[6]++;
}
