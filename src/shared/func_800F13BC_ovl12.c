/* Shared body (DK-5), from the banked draft of func_800F13BC_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

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
    animate_object(e);
    move_object(e);
}
