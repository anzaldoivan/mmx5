#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800FDF20_ovl07(Ent800FE04C* e) {
    e->unk6++;
    e->unk20 = 0x18000;
    e->unk24 = 0;
}

extern u8 D_800FFFA4_ovl34[][8];

extern s32 func_800FEF10_ovl34(EntFE308*, s32);

void func_800FE308_ovl34(EntFE308* e) {
    s32 r;
    u8* p;
    u16 y;
    s32 t;

    animate_object(e);
    move_object(e);
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
