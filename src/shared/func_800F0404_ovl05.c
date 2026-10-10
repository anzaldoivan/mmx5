/* Shared body (DK-5), from the banked draft of func_800F0404_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"

typedef struct Ent0404 {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0x45 - 0x7];
    /* 0x45 */ signed char unk45;
    /* 0x46 */ u8 pad46[0x67 - 0x46];
    /* 0x67 */ u8 unk67;
} Ent0404;

void DEDUP_NAME(Ent0404* e) {
    if (e->unk45 == 1) {
        e->unk67 = 0;
        e->unk5 = 2;
        e->unk6 = 0;
    }
}
