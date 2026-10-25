/* Shared body (DK-5), from the banked draft of func_800F27A8_ovl02 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

#define SPAD D_1F80004C.bytes

void DEDUP_NAME(u8* obj) {
    u8 v;

    if (--*(s16*)(obj + 0x7C) == -1) {
        v = 4;
        if (SPAD[0x80] == 0) {
            v = 3;
        }
        obj[5] = v;
        SPAD[0x80] ^= 1;
        obj[6] = 0;
    }
}
