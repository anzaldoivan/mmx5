/* Shared body (DK-5), from the banked draft of func_800F0688_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"

#define G (*(u8**)0x1F80004C)

void DEDUP_NAME(u8* arg0) {
    *(s32*)(G + 0x88) -= *(s32*)(G + 0x8C);
    *(s32*)(G + 0x8C) += 0x4000;
    if (*(s16*)(G + 0x8A) <= 0) {
        G[0x87] = 0;
        *(s32*)(G + 0x88) = 0;
        G[0x86] = 0x14;
        arg0[5] = 2;
        arg0[6] = 0;
    }
}
