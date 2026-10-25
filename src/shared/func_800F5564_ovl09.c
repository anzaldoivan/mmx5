/* Shared body (DK-5), from the banked draft of func_800F5564_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern u16 D_800D50DE;
extern u16 D_8009A42E;
extern u16 D_80093E68;

void DEDUP_NAME(u8* arg0) {
    if ((s16)(++*(s16*)(arg0 + 0x7C) % 5) == 0) {
        D_800D50DE++;
        D_8009A42E += 0x20;
        D_80093E68 += 0x400;
        if (D_800D50DE == 0x1F) {
            *(s16*)(arg0 + 0x7C) = 0xB4;
            *(s16*)(arg0 + 0x7E) = 0;
            arg0[6]++;
        }
    }
}
