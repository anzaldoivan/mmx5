/* Shared body (DK-5), from the banked draft of func_800FAD10_ovl58 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_80091C44;
extern D_8009A1F8_AD10_t D_8009A1F8;
extern void DEDUP_CALLEE(s32, s32, s32);

void DEDUP_NAME(UnkObj* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8_AD10_t* p = &D_8009A1F8;

        p->unkAB = 1;
        p->unkB2 = 0;
        p->unkB6 = 0x300;
        p->unkF4 = 1;
        arg0->unk1++;
        arg0->unk6 = 0;
        DEDUP_CALLEE(0x65, 0xFF, 0);
    }
}
