#include "types.h"

extern X4_Obj* func_8002D27C(void);

void func_800F2BCC_ovl04(X4_Obj* e, u8 arg1) {
    X4_Obj* o;

    o = func_8002D27C();
    if (o != 0) {
        o->active = 0x41;
        o->id = 6;
        o->unk2 = arg1;
        o->unk40 = e->unk40;
        o->unk42 = e->unk42 & 0x7FFF;
        o->animation_table = e->animation_table;
        o->unk3C = e->unk3C;
        o->bg_offset = e->bg_offset;
        o->x_pos.val = e->x_pos.val;
        o->y_pos.val = e->y_pos.val;
        o->unk50 = e;
        o->state = 0;
    }
}
