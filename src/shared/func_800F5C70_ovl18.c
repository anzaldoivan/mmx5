/* Shared body (DK-5), from the banked draft of func_800F5C70_ovl18 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_800D1C00[];

void DEDUP_NAME(u8 arg0) {
    D_800D1C00[0x11] = arg0;
    D_800D1C00[0x14] = arg0;
    D_800D1C00[0x16] = arg0;
    D_800D1C00[0x17] = arg0;
}
