/* Shared body (DK-5), from the banked draft of func_800F5608_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(Obj3DD4* o) {
    ObjFAF38* c;

    if (++o->unk7E == 10) {
        c = func_8002D1A4();
        if (c != 0) {
            c->unk0 = 0x41;
            c->unk1 = 0x10;
            c->unk2 = 0xE;
            c->unk7C = o;
        }
        o->unk7E = 0;
    }
    if (--o->unk7C == 0) {
        set_animation(o, 1);
        o->unk7C = 0;
        o->unk6++;
    }
}
