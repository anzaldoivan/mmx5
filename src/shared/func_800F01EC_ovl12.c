/* Shared body (DK-5), from the banked draft of func_800F01EC_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

extern s16 D_8009A0AA;
extern void func_800171E8(Ent*, s32);
extern void func_80017248(Ent*);
extern void func_8002DED4(Ent*);

void DEDUP_NAME(Ent* e) {
    func_800171E8(e, 4);
    if (D_8009A0AA > e->y) {
        e->flag15 = 0x40;
    } else {
        e->flag15 = 0;
    }
    e->state++;
    func_80017248(e);
    func_8002DED4(e);
}
