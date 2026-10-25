/* Shared body (DK-5), from the banked draft of func_800F092C_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern s16 D_800FD9CC_ovl28[];
extern s16 D_8009A0AA;

void DEDUP_NAME(Obj092C* arg0) {
    Scr092C* s;
    s16 lim;
    s32 d;

    if (arg0->unk67 != 0) {
        return;
    }
    if (arg0->unk5 == 4) {
        return;
    }
    if (arg0->unk5 == 5) {
        return;
    }
    s = D_1F80004C.scr092c;
    lim = D_800FD9CC_ovl28[s->unk81];
    if (arg0->unk2 == 3) {
        if (s->unk89 == 0) {
            arg0->unk5 = 4;
            arg0->unk6 = 0;
        } else {
            s->unk89--;
        }
        return;
    }
    d = D_8009A0AA - arg0->unkA;
    if ((d >= 0) ? (d <= lim) : (arg0->unkA - D_8009A0AA <= lim)) {
        arg0->unk5 = 4;
        arg0->unk6 = 0;
    }
}
