#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

#define D_80101E80_ovl07 D_80100044_ovl34

#define func_800FDA54_ovl07 func_800FDE1C_ovl34
#include "shared/func_800FDA54_ovl07.c"
#undef func_800FDA54_ovl07
#undef D_80101E80_ovl07

#define func_800FDAE0_ovl07 func_800FDEA8_ovl34
#include "shared/func_800FDAE0_ovl07.c"
#undef func_800FDAE0_ovl07

extern u8 D_800FFFA4_ovl34[][8];

extern s32 func_800FEF10_ovl34(EntFDC6C*, s32);

void func_800FDEC8_ovl34(EntFDC6C* e) {
    s32 r;
    u8* p;
    s32 t;

    animate_object(e);
    move_object(e);
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
