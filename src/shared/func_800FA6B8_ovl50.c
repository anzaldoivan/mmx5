/* Shared body (DK-5), from the banked draft of func_800FA6B8_ovl50 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_80091C44;
extern UnkSpawn* DEDUP_CALLEE(void);

void DEDUP_NAME(UnkObj* obj) {
    UnkSpawn* s;

    if (D_80091C44 == 0) {
        s = DEDUP_CALLEE();
        if (s != 0) {
            s->unk0 = 0x41;
            s->unk1 = 0x1D;
            s->unk2 = 0;
            s->unkA = 0x100;
            s->unkE = 0x7C;
            s->unk54 = 7;
        }
        obj->unk4 = 1;
        obj->unk1++;
    }
}
