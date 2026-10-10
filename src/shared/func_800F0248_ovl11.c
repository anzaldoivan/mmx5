/* Shared body (DK-5), from the banked draft of func_800F0248_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

typedef struct Ent0248 {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 pad5[2];
    /* 0x07 */ u8 unk7;
    /* 0x08 */ u8 pad8[0x68 - 0x8];
    /* 0x68 */ s32 unk68;
    /* 0x6C */ u8 pad6C[0x87 - 0x6C];
    /* 0x87 */ u8 unk87;
} Ent0248;

void DEDUP_NAME(Ent0248* arg0) {
    arg0->unk68 = 0;
    arg0->unk4 = 4;
    arg0->unk7 = 1;
    arg0->unk87 = 0x50;
}
