/* Shared body (DK-5), from the banked draft of func_800FAA00_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/ovl06.h"
#include "mmx5/globals.h"
#include "addr.h"

void DEDUP_NAME(u8* obj) {
    D_1F80004C.bytes[0x8A] = 0;
    animate_object(obj);
    func_800F9180_ovl06(obj);
}
