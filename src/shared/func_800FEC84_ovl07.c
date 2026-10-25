/* Shared body (DK-5), from the banked draft of func_800FEC84_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"

extern s16 D_80101DFC_ovl07[][4];

s32 DEDUP_NAME(u8* arg0, u8 idx, s16 x, s16 y) {
    s16* pos = *(s16**)(arg0 + 0x84);

    if (D_80101DFC_ovl07[idx][0] + pos[0] - 4 < x &&
        x < D_80101DFC_ovl07[idx][1] + pos[0] + 4 &&
        D_80101DFC_ovl07[idx][2] + pos[1] - 4 < y &&
        y < D_80101DFC_ovl07[idx][3] + pos[1] + 4) {
        return 0;
    }
    return 1;
}
