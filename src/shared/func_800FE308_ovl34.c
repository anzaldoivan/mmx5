/* Shared body (DK-5), from the banked draft of func_800FE308_ovl34 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_800FFFA4_ovl34[][8];

extern void func_80017248(EntFE308*);
extern void func_8002DF54(EntFE308*);
extern s32 func_800FEF10_ovl34(EntFE308*, s32);

void DEDUP_NAME(EntFE308* e) {
    s32 r;
    u8* p;
    u16 y;
    s32 t;

    func_80017248(e);
    func_8002DF54(e);
    r = func_800FEF10_ovl34(e, 0);
    switch (r) {
    case 2:
        e->unk5 = D_800FFFA4_ovl34[e->unk8C][4];
        e->unk6 = 0;
        break;
    case 1:
        t = D_800FFFA4_ovl34[e->unk8C][0];
        p = e->unk68;
        y = e->unkA;
        e->unk6 = 0;
        e->unk5 = t;
        e->unkA = y - ((y + (signed char)p[0] - p[2]) & 0xF);
        break;
    }
}
