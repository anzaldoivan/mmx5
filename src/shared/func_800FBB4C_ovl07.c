/* Shared body (DK-5), from the banked draft of func_800FBB4C_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

void DEDUP_NAME(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == -1) {
        D_1F80004C.bytes[0x92] = 0;
        *(s16*)(obj + 0x7E) = 0;
        obj[6]++;
    }
    DEDUP_CALLEE(obj);
}
