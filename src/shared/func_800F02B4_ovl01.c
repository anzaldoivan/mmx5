/* Shared body (DK-5), from the banked draft of func_800F02B4_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern s16 D_8009A0AA;

void DEDUP_NAME(u8* arg0) {
    if ((D_8009A0AA - *(s16*)(arg0 + 0xA)) >= 0xB5) {
        arg0[0x7A] = 0;
        arg0[0x5] = 2;
    }
}
