/* Shared body (DK-5), from the banked draft of func_800FCB98_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"

// from rockx5 800FCB98: spawned child copies the parent's state, keeps the parent at 0x50
extern ObjFAF38* DEDUP_CALLEE(void);

void DEDUP_NAME(ObjFAF38* arg0, s16 arg1, s16 arg2, u8 arg3) {
    ObjFAF38* obj = DEDUP_CALLEE();

    if (obj != 0) {
        obj->unk0 = 0x41;
        obj->unk1 = 0x1E;
        obj->unk2 = arg3;
        obj->unk40 = arg0->unk40;
        obj->unk42 = arg0->unk42 & 0x7FFF;
        obj->unk30 = arg0->unk30;
        obj->unk3C = arg0->unk3C;
        obj->unk14 = arg0->unk14;
        obj->unkA = arg1;
        obj->unk8 = 0;
        obj->unkE = arg2;
        obj->unkC = 0;
        *(ObjFAF38**)&obj->pad44[0xC] = arg0; /* 0x50: the parent */
    }
}
