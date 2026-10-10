/* Shared body (DK-5), from the banked draft of func_800F0D1C_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"

typedef struct Ent800F0D1C {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 pad6[4];
    /* 0x0A */ s16 y;
    /* 0x0C */ u8 padC[9];
    /* 0x15 */ u8 unk15;
} Ent800F0D1C;

extern s16 D_8009A0AA;

void DEDUP_NAME(Ent800F0D1C* e) {
    if (D_8009A0AA - e->y >= 0xB0) {
        e->unk15 = 0x40;
        e->unk4 = 1;
        e->unk5 = 3;
    }
}
