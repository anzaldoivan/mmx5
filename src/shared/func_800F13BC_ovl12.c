/* Shared body (DK-5), from the banked draft of func_800F13BC_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_800317B8(Ent13BC*);
extern void func_8002D9EC(Ent13BC*, s32, s32);
extern void func_80017248(Ent13BC*);
extern void func_8002DF54(Ent13BC*);

void DEDUP_NAME(Ent13BC* e) {
    Ent13BC* q;
    Ent13BC* p;

    func_800317B8(e);
    if (e->sub == 0) {
        if (++e->timer == 200) {
            e->state = 2;
        }
    }
    q = e->parent;
    p = q->parent;
    if (p->state == 2 || p->sub == 9) {
        e->state = 2;
    }
    func_8002D9EC(e, 16, 16);
    func_80017248(e);
    func_8002DF54(e);
}
