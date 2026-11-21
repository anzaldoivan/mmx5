#include "types.h"

extern X4_Obj* find_free_visual_obj(void);

void func_800FCD04_ovl38(X4_Obj* e, u8 arg1) {
    X4_Obj* o;

    o = find_free_visual_obj();
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
