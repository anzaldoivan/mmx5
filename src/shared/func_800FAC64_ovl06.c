/* Shared body (DK-5), from the banked draft of func_800FAC64_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

void DEDUP_NAME(u8* arg0) {
    s16 count;

    count = *(s16*)(arg0 + 0x7E);
    if (count == 0 || count - 1 == D_1F80004C.bytes[0x8B]) {
        arg0[6]++;
    }
}
