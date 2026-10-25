/* Shared body (DK-5), from the banked draft of func_800F1BDC_ovl26 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void DEDUP_CALLEE(u8*, s32);
extern s16 D_8009A0AA;
extern s16 D_8009A1F8[];

void DEDUP_NAME(u8* o) {
    DEDUP_CALLEE(o, 0);
    *(s32*)(o + 0x54) = 0;
    *(s32*)(o + 0x50) = 0;
    *(s32*)(o + 0x20) = 0;
    *(s32*)(o + 0x24) = 0;
    *(s16*)(o + 0x7C) = 0x3C;
    if (D_8009A0AA - D_8009A1F8[5] >= 0xA1) {
        o[0x15] = 0x40;
        D_1F80004C.scr84->unk84 = 0;
        *(s16*)(o + 0xA) = D_8009A1F8[5] + 0x40;
        o[6]++;
    } else {
        o[0x15] = 0;
        D_1F80004C.scr84->unk84 = 1;
        *(s16*)(o + 0xA) = D_8009A1F8[5] + 0x100;
        o[6]++;
    }
}
