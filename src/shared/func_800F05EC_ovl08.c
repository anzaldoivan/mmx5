/* Shared body (DK-5), from the banked draft of func_800F05EC_ovl08 by tools/wave/gate.py rescan. */
#include "types.h"

extern s16 D_8009A0AA;

void DEDUP_NAME(u8* obj) {
    if (D_8009A0AA - *(s16*)(obj + 0xA) >= 0xBD) {
        obj[0x7A] = 0;
        if (obj[0x80] == 0) {
            obj[0x5] = 2;
            obj[0x6] = 0;
            return;
        }
        *(s16*)(obj + 0x7C) = 1;
        obj[0x5] = 7;
        obj[0x6] = 0;
    }
}
