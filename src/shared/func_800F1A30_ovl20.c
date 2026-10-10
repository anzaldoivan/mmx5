/* Shared body (DK-5), from the banked draft of func_800F1A30_ovl20 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_80091C44;

void DEDUP_NAME(UnkSpawn* arg0) {
    if (D_80091C44 == 0) {
        arg0->unk1 = 2;
        arg0->unk2 = 0;
    }
}
