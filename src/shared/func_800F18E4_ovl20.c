/* Shared body (DK-5), from the banked draft of func_800F18E4_ovl20 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_80091C44;
extern s8 D_800D1C28[];

void DEDUP_NAME(u8* arg0) {
    if (D_80091C44 == 0) {
        D_800D1C28[0] = 0;
        arg0[2]++;
    }
}
