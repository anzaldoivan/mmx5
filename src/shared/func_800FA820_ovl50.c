/* Shared body (DK-5), from the banked draft of func_800FA820_ovl50 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_80091C44;
extern u8 D_8009A1F8[];

void DEDUP_NAME(u8* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8[3] = 1;
        arg0[1]++;
    }
}
