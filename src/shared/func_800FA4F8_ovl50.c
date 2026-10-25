/* Shared body (DK-5), from the banked draft of func_800FA4F8_ovl50 by tools/wave/gate.py rescan. */
#include "types.h"

extern D_8009A1F8_60_t D_8009A1F8;
void DEDUP_CALLEE(s32, s32, s32);

void DEDUP_NAME(Ovl45State* s) {
    D_8009A1F8.unk60 += 0x44444;
    if (++s->unk4 >= 30) {
        DEDUP_CALLEE(0x26, 0xFF, 0);
        D_8009A1F8.unk60 = 0x1000000;
        s->unk4 = 0;
        s->unk1++;
    }
}
