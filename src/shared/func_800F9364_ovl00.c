/* Shared body (DK-5), from the banked draft of func_800F9364_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(Ent9364*, s32);
extern void func_80017248(Ent9364*);
extern void func_8002DED4(Ent9364*);
extern u8 D_800FB448_ovl00[][6];

void DEDUP_NAME(Ent9364* e) {
    if (e->unk46 == 0) {
        u8 t;
        func_800171E8(e, 0);
        t = D_800FB448_ovl00[e->unk8D][e->unk8E++];
        e->unk6 = 0;
        e->unk5 = t;
    }
    func_80017248(e);
    func_8002DED4(e);
}
