/* Shared body (DK-5), from the banked draft of func_800F6BF4_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(Ent6BF4* e) {
    Ent6BF4* p;

    p = e->unk7C;
    e->unkA = p->unkA;
    e->unkE = p->unkE;
    switch (e->unk5) {
    case 0:
        if (p->unk45 == 1) {
            set_animation(e, 6);
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
    animate_object(e);
    apply_object_motion(e);
}
