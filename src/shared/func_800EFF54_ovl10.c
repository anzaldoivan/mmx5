/* Shared body (DK-5), from the banked draft of func_800EFF54_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_8009A0A0[];
extern void DEDUP_CALLEE(u8* obj);

void DEDUP_NAME(u8* obj) {
    u8* g = D_8009A0A0;
    s32 d;

    d = *(s16*)(g + 0xA) - *(s16*)(obj + 0xA);
    if ((d >= 0) ? (d < 0x40)
                 : (*(s16*)(obj + 0xA) - *(s16*)(g + 0xA) < 0x40)) {
        u8* h = D_8009A0A0;

        d = *(s16*)(h + 0xE) - *(s16*)(obj + 0xE);
        if (d >= 0) {
            d = d < 0x40;
        } else {
            d = *(s16*)(obj + 0xE) - *(s16*)(h + 0xE) < 0x40;
        }
        if (d || (obj[0x47] != 0 && obj[0x47] != 6)) {
            DEDUP_CALLEE(obj);
        }
    } else if (obj[0x47] != 0 && obj[0x47] != 6) {
        DEDUP_CALLEE(obj);
    }
}
