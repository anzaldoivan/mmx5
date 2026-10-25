/* Shared body (DK-5), from the banked draft of func_800FB7EC_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_800FF684_ovl06[];
extern u8 D_800FF688_ovl06[];

void DEDUP_NAME(u8* obj) {
    if (obj[0x47] == 11) {
        *(u8**)(obj + 0x50) = D_800FF684_ovl06;
        *(u8**)(obj + 0x54) = D_800FF688_ovl06;
    }
    if (--*(s16*)(obj + 0x88) == 0) {
        *(s32*)(obj + 0x50) = 0;
        obj[4] = 3;
        obj[7] = 0;
    }
}
