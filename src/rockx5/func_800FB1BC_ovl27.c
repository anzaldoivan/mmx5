#include "types.h"

extern X4_Obj* func_8002D0E4(void);

void func_800FB1BC_ovl27(X4_Obj* e, u8 arg1) {
    X4_Obj* o;

    o = func_8002D0E4();
    if (o != 0) {
        o->active = 0x41;
        o->id = 0xA;
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
