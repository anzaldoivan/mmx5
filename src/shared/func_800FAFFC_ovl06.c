/* Shared body (DK-5), from the banked draft of func_800FAFFC_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

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
