/* Shared body (DK-5), from the banked draft of func_800F0D34_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"

extern Obj800F0D34* DEDUP_CALLEE(void);

void DEDUP_NAME(Obj800F0D34* obj) {
    Obj800F0D34* s = DEDUP_CALLEE();

    if (s != 0) {
        s->unk0 = 0x41;
        s->unk1 = 5;
        s->unk2 = obj->unk2;
        s->unk40 = obj->unk40;
        s->unk42 = obj->unk42 & 0x7FFF;
        s->unk30 = obj->unk30;
        s->unk3C = obj->unk3C;
        s->unk14 = obj->unk14;
        s->unk8 = obj->unk8;
        s->unkC = obj->unkC;
        s->unk50 = obj;
        s->unk4 = 0;
    }
}
