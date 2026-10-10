/* Shared body (DK-5), from the banked draft of func_800F0FC8_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"

typedef struct Ent0FC8 {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ signed char unk2;
    /* 0x03 */ u8 pad3[3];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0x20 - 7];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
} Ent0FC8;

#define SCRATCH_CTX (*(Ctx0F18**)0x1F80004C)

void DEDUP_NAME(Ent0FC8* a0) {
    a0->unk20 = 0;
    a0->unk28 = 0;
    a0->unk24 = 0;
    a0->unk2C = 0;
    a0->unk6++;
    if (a0->unk2 == 3) {
        SCRATCH_CTX->unk80 = 1;
    } else {
        SCRATCH_CTX->unk80 = 20;
    }
}
