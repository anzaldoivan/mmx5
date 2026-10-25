/* Shared body (DK-5), from the banked draft of func_800FA990_ovl50 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 DEDUP_CALLEE(void);
extern u8 D_80091C44;
extern s16 D_8009A2AE;

void DEDUP_NAME(Unk800FAD8C* arg0) {
    if (++arg0->unk6 & 1) {
        D_8009A2AE = (DEDUP_CALLEE() % 5) + 0x104;
    } else {
        D_8009A2AE = 0x100;
    }
    if (D_80091C44 == 0) {
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
