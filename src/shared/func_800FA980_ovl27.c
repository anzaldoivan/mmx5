/* Shared body (DK-5), from the banked draft of func_800FA980_ovl27 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

void DEDUP_NAME(u8* arg0) {
    if (*(s8*)(arg0 + 0x45) != 0) {
        *(*(u8**)(D_1F80004C.bytes + 0x80) + 0x88) = 1;
        *(s32*)(arg0 + 0x50) = 0;
        *(s32*)(arg0 + 0x54) = 0;
        arg0[3] = 0;
        arg0[4] = 4;
    }
}
