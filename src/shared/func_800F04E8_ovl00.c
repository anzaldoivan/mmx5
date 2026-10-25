/* Shared body (DK-5), from the banked draft of func_800F04E8_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

#define G D_1F80004C.bytes
void DEDUP_NAME(u8* arg0) {
    *(s32*)(G + 0x88) -= *(s32*)(G + 0x8C);
    if (*(s16*)(G + 0x8A) <= 0) {
        G[0x87] = 0;
        *(s32*)(G + 0x88) = 0;
        G[0x91] = 1;
        arg0[5] = 3;
        arg0[6] = 0;
    }
}
