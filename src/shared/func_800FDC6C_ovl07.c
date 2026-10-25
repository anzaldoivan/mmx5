/* Shared body (DK-5), from the banked draft of func_800FDC6C_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_80101DE0_ovl07[][8];

extern void func_80017248(EntFDC6C*);
extern void func_8002DF54(EntFDC6C*);
extern s32 func_800FEB48_ovl07(EntFDC6C*, s32);

void DEDUP_NAME(EntFDC6C* e) {
    s32 r;
    u8* p;
    u16 y;
    s32 t;

    func_80017248(e);
    func_8002DF54(e);
    r = func_800FEB48_ovl07(e, 3);
    switch (r) {
    case 2:
        e->unk5 = D_80101DE0_ovl07[e->unk8C][7];
        e->unk6 = 0;
        break;
    case 1:
        p = e->unk68;
        t = D_80101DE0_ovl07[e->unk8C][3];
        y = e->unkE;
        e->unk6 = 0;
        e->unk5 = t;
        e->unkE = y - ((y + (signed char)p[1] - p[3]) & 0xF);
        break;
    }
}
