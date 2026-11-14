#include "types.h"

extern u8 D_80101DE0_ovl07[][8];

extern void func_80017248(EntFDC6C*);
extern void func_8002DF54(EntFDC6C*);
extern s32 func_800FEB48_ovl07(EntFDC6C*, s32);

void func_800FDB00_ovl07(EntFDC6C* e) {
    s32 r;
    u16 t;
    s32 y;
    u8* p;

    func_80017248(e);
    func_8002DF54(e);
    r = func_800FEB48_ovl07(e, 1);
    switch (r) {
    case 2:
        e->unk5 = D_80101DE0_ovl07[e->unk8C][5];
        e->unk6 = 0;
        break;
    case 1:
        t = D_80101DE0_ovl07[e->unk8C][1];
        e->unk6 = 0;
        e->unk5 = t;
        p = e->unk68;
        y = e->unkE;
        e->unkE = (-(e->unkE + (signed char)p[1] + p[3]) & 0xF) + y;
        break;
    }
}
