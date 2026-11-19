#include "types.h"
#include "mmx5/object.h"

extern u8 D_800FAB34_ovl09[][8];

extern s32 func_800F1B40_ovl09(Ent170C*, s32);

void func_800F15FC_ovl09(Ent170C* e) {
    s32 r;
    s32 t;
    u8* p;

    move_object(e);
    r = func_800F1B40_ovl09(e, 1);
    switch (r) {
    case 2:
        e->unk5 = D_800FAB34_ovl09[e->unk8F][5];
        e->unk6 = 0;
        break;
    case 1:
        e->unk5 = D_800FAB34_ovl09[e->unk8F][1];
        e->unk6 = 0;
        p = e->unk68;
        t = e->unkE;
        e->unkE = (-(e->unkE + (signed char)p[1] + p[3]) & 0xF) + t;
        break;
    }
}
