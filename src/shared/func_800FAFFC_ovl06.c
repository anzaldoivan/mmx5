/* Shared body (DK-5), from the banked draft of func_800FAFFC_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

// from rockx5 800FAFFC: spawned child copies the parent's state, keeps the parent at 0x50
typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[5];
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x1A];
    /* 0x30 */ s32 unk30;
    /* 0x34 */ u8 pad34[8];
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ s16 unk40;
    /* 0x42 */ u16 unk42;
    /* 0x44 */ u8 pad44[0xC];
    /* 0x50 */ void* unk50; /* the parent */
} ObjFAFFC;

extern ObjFAFFC* DEDUP_CALLEE(void);

void DEDUP_NAME(ObjFAFFC* arg0, s16 arg1, s16 arg2, u8 arg3) {
    ObjFAFFC* obj = DEDUP_CALLEE();

    if (obj != 0) {
        obj->unk0 = 0x41;
        obj->unk1 = 6;
        obj->unk2 = arg3;
        obj->unk15 = arg0->unk15;
        obj->unk40 = arg0->unk40;
        obj->unk42 = arg0->unk42 & 0x7FFF;
        obj->unk30 = arg0->unk30;
        obj->unk3C = arg0->unk3C;
        obj->unk14 = arg0->unk14;
        obj->unkA = arg1;
        obj->unk8 = 0;
        obj->unkE = arg2;
        obj->unkC = 0;
        obj->unk50 = arg0;
    }
}
