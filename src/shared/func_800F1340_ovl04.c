/* Shared body (DK-5), from the banked draft of func_800F1340_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern Obj66A0 D_8009A0A0;
extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern void func_8002DF54(Obj66A0*);

void DEDUP_NAME(Obj66A0* e) {
    s32 a;
    s32 px;
    s32 py;

    px = D_8009A0A0.unkA;
    py = D_8009A0A0.unkE;
    a = ratan2(e->unkE - py, px - e->unkA);
    e->unk20 = rcos(a) << 6;
    e->unk24 = rsin(a) << 6;
    if (D_8009A0A0.unkA < e->unkA) {
        e->unk15 = 0;
    } else {
        e->unk15 = 0x40;
    }
    e->pad6[0]++;
    func_8002DF54(e);
}
