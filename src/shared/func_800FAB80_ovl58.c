/* Shared body (DK-5), from the banked draft of func_800FAB80_ovl58 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_80091C44;
extern s32 D_8009A420;
extern u16 D_800D50DE;
extern u16 D_80093E68;
extern u16 D_8009A42E;

void DEDUP_NAME(u8* arg0) {
    if (D_80091C44 == 0) {
        if (!(D_8009A420 & 1)) {
            D_800D50DE++;
            D_8009A42E += 0x20;
            D_80093E68 += 0x400;
        }
        if (D_800D50DE >= 0x1F) {
            *(s16*)(arg0 + 4) = 0;
            arg0[1]++;
        }
    }
}
