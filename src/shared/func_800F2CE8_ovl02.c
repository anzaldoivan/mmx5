/* Shared body (DK-5), from the banked draft of func_800F2CE8_ovl02 by tools/wave/gate.py rescan. */
#include "types.h"

// rockx5 800F2CE8: child copies parent's 0x50/0x15/0xA/0xE, advances step
typedef struct Ent2CE8 {
    /* 0x00 */ u8 pad0[3];
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 pad5[5];
    /* 0x0A */ u16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u8 pad10[5];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x50 - 0x16];
    /* 0x50 */ s32 unk50;
    /* 0x54 */ u8 pad54[0x60 - 0x54];
    /* 0x60 */ u8 unk60;
    /* 0x61 */ u8 pad61[0x7C - 0x61];
    /* 0x7C */ void* unk7C; /* the parent Ent2CE8 */
} Ent2CE8;

void DEDUP_NAME(Ent2CE8* arg0) {
    Ent2CE8* parent = arg0->unk7C;

    arg0->unk60 = 4;
    arg0->unk50 = parent->unk50;
    arg0->unk15 = parent->unk15;
    arg0->unkA = parent->unkA;
    arg0->unkE = parent->unkE;
    arg0->unk3 = 0;
    arg0->unk4++;
}
