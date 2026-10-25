/* Shared body (DK-5), from the banked draft of func_800F2D24_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

void DEDUP_NAME(u8* arg0) {
    u8 v = (*(u8**)(D_1F80004C.bytes + 0x80))[0x8A];

    if (v == 1) {
        arg0[5] = 3;
    } else if (v == 2) {
        arg0[5] = 4;
    }
}
