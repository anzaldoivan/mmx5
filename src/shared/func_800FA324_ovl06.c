/* Shared body (DK-5), from the banked draft of func_800FA324_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/ovl06.h"
#include "mmx5/globals.h"

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    if (++*(s16*)(obj + 0x7C) >= 90) {
        func_800F9180_ovl06(obj);
    }
}
