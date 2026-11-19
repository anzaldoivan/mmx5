/* Shared body (DK-5), from the banked draft of func_800F2634_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"

#define G ((s8*)D_1F80004C.bytes)
void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj, 2);
    G[0x89] = 1;
    G[0x80] = -0x1A;
    G[0x81] = -0x18;
    G[0x82] = 0x18;
    G[0x83] = 0xE;
    obj[6]++;
}
