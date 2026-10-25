/* Shared body (DK-5), from the banked draft of func_800F0494_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

#define G D_1F80004C.bytes
void DEDUP_NAME(u8* arg0) {
    if (--G[0x86] == 0xFF) {
        *(s32*)(G + 0x8C) = 0x10000;
        arg0[6]++;
    }
}
