/* Shared body (DK-5), from the banked draft of func_800FC988_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/ovl07.h"
#include "mmx5/globals.h"
#include "addr.h"

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == -1) {
        D_1F80004C.bytes[0x88] = 0x3C;
        func_800FB030_ovl07(obj);
    }
}
