/* Shared body (DK-5), from the banked draft of func_800F15AC_ovl26 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_8009A0A0[];
extern s16 D_8009A202;
extern void DEDUP_CALLEE(Ent15AC*);

#define PLR ((Ent15AC*)D_8009A0A0)
#define ABS(x) ((x) < 0 ? -(x) : (x))

void DEDUP_NAME(Ent15AC* o) {
    if (ABS(PLR->unkE - o->unkE) >= 4) {
        if (PLR->unkE >= o->unkE) {
            o->unk24 = -0x10000;
        } else {
            o->unk24 = 0x10000;
        }
    } else {
        o->unk24 = 0;
    }
    DEDUP_CALLEE(o);
    o->unkA = D_8009A202 + 0x40;
    if (--o->unk7C == -1) {
        o->unk5 = 4;
        o->unk6 = 0;
    }
    if (ABS(PLR->unkA - o->unkA) < 0x21) {
        o->unk6 = 0;
    }
}
