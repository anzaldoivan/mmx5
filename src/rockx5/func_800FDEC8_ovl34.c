#include "types.h"

extern u8 D_800FFFA4_ovl34[][8];

extern void func_80017248(EntFDC6C*);
extern void func_8002DF54(EntFDC6C*);
extern s32 func_800FEF10_ovl34(EntFDC6C*, s32);

void func_800FDEC8_ovl34(EntFDC6C* e) {
    s32 r;
    u8* p;
    s32 t;

    func_80017248(e);
    func_8002DF54(e);
    r = func_800FEF10_ovl34(e, 1);
    switch (r) {
    case 2:
        e->unk5 = D_800FFFA4_ovl34[e->unk8C][5];
        e->unk6 = 0;
        break;
    case 1:
        t = D_800FFFA4_ovl34[e->unk8C][1];
        e->unk6 = 0;
        e->unk5 = t;
        p = e->unk68;
        {
            s32 v = e->unkE;
            e->unkE = (-(e->unkE + (signed char)p[1] + p[3]) & 0xF) + v;
        }
        break;
    }
}
