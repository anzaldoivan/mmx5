/* Shared body (DK-5), from the banked draft of func_800EFB28_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern s8 D_800D1C44;
extern s16 D_8009A0AA;

void DEDUP_NAME(u8* o) {
    s32 d;

    if (--*(s16*)(o + 0x7C) == -1 || D_1F80004C.bytes[0x85] != 0) {
        o[6]++;
    } else if (D_800D1C44 == 0) {
        d = D_8009A0AA - *(s16*)(o + 0xA);
        if ((d >= 0) ? (d < 0x90) : (*(s16*)(o + 0xA) - D_8009A0AA < 0x90)) {
            o[6]++;
        }
    } else {
        d = D_8009A0AA - *(s16*)(o + 0xA);
        if ((d >= 0) ? (d < 0x70) : (*(s16*)(o + 0xA) - D_8009A0AA < 0x70)) {
            o[6]++;
        }
    }
}
