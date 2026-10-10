/* Shared body (DK-5), from the banked draft of func_800FA190_ovl42 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_800D1F3C;

void DEDUP_NAME(u8* arg0) {
    if (D_800D1F3C == 2) {
        arg0[1]++;
    }
}
