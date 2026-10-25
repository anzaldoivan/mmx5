/* Shared body (DK-5), from the banked draft of func_800F5648_ovl27 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

void DEDUP_NAME(u8* arg0) {
    if (*(s8*)(arg0 + 0x45) != 0) {
        D_1F80004C.bytes[0x87] = 0;
        arg0[5] = 3;
        arg0[6] = 0;
    }
}
