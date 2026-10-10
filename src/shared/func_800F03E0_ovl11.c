/* Shared body (DK-5), from the banked draft of func_800F03E0_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_800D1C00[];

void DEDUP_NAME(u8 a0) {
    D_800D1C00[0x10] = a0;
    D_800D1C00[0x11] = a0;
    D_800D1C00[0x12] = a0;
    D_800D1C00[0x13] = a0;
    D_800D1C00[0x14] = a0;
    D_800D1C00[0x15] = a0;
    D_800D1C00[0x16] = a0;
    D_800D1C00[0x17] = a0;
    D_800D1C00[0x19] = a0;
}
