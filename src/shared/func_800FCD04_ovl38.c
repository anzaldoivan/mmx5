/* Shared body (DK-5), from the banked draft of func_800FCD04_ovl38 by tools/wave/gate.py rescan. */
#include "types.h"

extern X4_Obj* DEDUP_CALLEE(void);

void DEDUP_NAME(X4_Obj* e, u8 arg1) {
    X4_Obj* o;

    o = DEDUP_CALLEE();
    if (o != 0) {
        o->active = 0x61;
        o->id = 0xE;
        o->unk2 = arg1;
        o->unk15 = e->unk15;
        o->unk40 = e->unk40;
        o->unk42 = e->unk42 & 0x7FFF;
        o->animation_table = e->animation_table;
        o->unk3C = e->unk3C;
        o->bg_offset = e->bg_offset;
        o->x_pos.i.hi = e->x_pos.i.hi;
        o->x_pos.i.lo = 0;
        o->y_pos.i.hi = e->y_pos.i.hi;
        o->y_pos.i.lo = 0;
        o->unk50 = e;
    }
}
