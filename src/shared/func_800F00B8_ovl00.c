/* Shared body (DK-5), from the banked draft of func_800F00B8_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/object.h"
#include "addr.h"

#define G D_1F80004C.bytes

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj);
    if (--G[0x86] == 0xFF) {
        obj[6]++;
    }
}
