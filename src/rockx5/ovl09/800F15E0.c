#include "types.h"
#include "mmx5/object.h"

void func_800F15E0_ovl09(Ent800FE04C* e) {
    e->unk6++;
    e->unk20 = 0;
    e->unk24 = 0x20000;
}

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

#define D_8007BD4C D_800FAB80_ovl09

#define func_800532E0 func_800F16B4_ovl09
#include "shared/func_800532E0.c"
#undef func_800532E0
