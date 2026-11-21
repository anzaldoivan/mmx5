#include "types.h"

extern X4_Obj* find_free_visual_obj(void);

void func_800F1B3C_ovl11(X4_Obj* e) {
    X4_Obj* o;

    o = find_free_visual_obj();
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
