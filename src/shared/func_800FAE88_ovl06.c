/* Shared body (DK-5), from the banked draft of func_800FAE88_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/ovl06.h"
#include "mmx5/globals.h"
#include "addr.h"

void DEDUP_NAME(ObjFA284* o) {
    animate_object(o);
    if (--o->timer == -1) {
        *(s16*)(D_1F80004C.bytes + 0x8E) = 0x3C;
        D_1F80004C.bytes[0x8A] = 0;
        D_1F80004C.bytes[0x8B] = 0;
        func_800F9180_ovl06(o);
    }
}
