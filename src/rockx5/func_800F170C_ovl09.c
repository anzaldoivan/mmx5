#include "types.h"

extern u8 D_800FAB34_ovl09[][8];

extern void func_8002DF54(Ent170C*);
extern s32 func_800F1B40_ovl09(Ent170C*, s32);

void func_800F170C_ovl09(Ent170C* e) {
    s32 r;
    u8* p;
    u16 y;
    s32 t;

    func_8002DF54(e);
    r = func_800F1B40_ovl09(e, 3);
    switch (r) {
    case 2:
        e->unk5 = D_800FAB34_ovl09[e->unk8F][7];
        e->unk6 = 0;
        break;
    case 1:
        p = e->unk68;
        t = D_800FAB34_ovl09[e->unk8F][3];
        y = e->unkE;
        e->unk6 = 0;
        e->unk5 = t;
        e->unkE = y - ((y + (signed char)p[1] - p[3]) & 0xF);
        break;
    }
}
