/* Shared body (DK-5), from the banked draft of func_800F6DB8_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(Ent6BF4*, s32);
extern void func_8002D9EC(Ent6BF4*, s32, s32);
extern void func_80017248(Ent6BF4*);
extern void func_8002DED4(Ent6BF4*);

void DEDUP_NAME(Ent6BF4* e) {
    Ent6BF4* p;

    p = e->unk7C;
    e->unkA = p->unkA;
    e->unkE = p->unkE;
    switch (e->unk5) {
    case 0:
        if (p->unk45 == 1) {
            func_800171E8(e, 7);
            e->unk5++;
        }
        break;
    case 1:
        if (e->unk46 == 0) {
            e->unk4++;
        }
        func_8002D9EC(e, 0x20, 0x20);
        break;
    }
    p = e->unk7C;
    if (p->unk5 == 11 || p->unk4 == 2) {
        e->unk4++;
    }
    func_80017248(e);
    func_8002DED4(e);
}
