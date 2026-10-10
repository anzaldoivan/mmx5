/* Shared body (DK-5), from the banked draft of func_800F0DA0_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"

typedef struct Ent0DA0 {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0x15 - 7];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x20 - 0x16];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x67 - 0x30];
    /* 0x67 */ u8 unk67;
} Ent0DA0;

#define SCR_4C (*(Ctx0F18**)0x1F80004C)

extern void DEDUP_CALLEE(Ent0DA0*, s32);

void DEDUP_NAME(Ent0DA0* e) {
    s32 v;

    v = -0x8000;
    e->unk67 = 1;
    e->unk6++;
    if (e->unk15 != 0) {
        v = 0x8000;
    }
    e->unk20 = v;
    e->unk28 = 0;
    e->unk24 = 0;
    e->unk2C = 0;
    SCR_4C->unk80 = 0x30;
    DEDUP_CALLEE(e, 0);
}
