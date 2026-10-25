/* Shared body (DK-5), from the banked draft of func_800F1B3C_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern X4_Obj* DEDUP_CALLEE(void);

void DEDUP_NAME(X4_Obj* e) {
    X4_Obj* o;

    o = DEDUP_CALLEE();
    if (o != 0) {
        o->active = 0x41;
        o->id = 0x10;
        o->unk2 = 0;
        o->unk50 = e;
        o->unk42 = e->unk42;
        o->animation_table = e->animation_table;
        o->unk3C = e->unk3C;
        o->unk40 = e->unk40;
        o->bg_offset = e->bg_offset;
        o->unk16 = 3;
        o->unk15 = e->unk15;
        o->x_pos = e->x_pos;
        o->y_pos = e->y_pos;
    }
}
