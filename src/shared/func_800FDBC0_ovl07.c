#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern void (*D_80101E88_ovl07[])(Ovl07Ent*);

void func_800FDBC0_ovl07(Ovl07Ent* e) {
    if (e->unk8E != 0 && ((Ovl07Ent*)e->unk7C)->unk8E == 2) {
        e->unk24 = -0x18000;
        e->unk20 = 0;
        e->unk8E = 0;
        e->unk5 = 5;
        e->unk6 = 0;
        return;
    }
    D_80101E88_ovl07[e->unk6](e);
}

void func_800FDC4C_ovl07(Ent800FE04C* e) {
    e->unk6++;
    e->unk20 = 0;
    e->unk24 = -0x18000;
}

extern u8 D_80101DE0_ovl07[][8];

extern s32 func_800FEB48_ovl07(EntFDC6C*, s32);

void func_800FDC6C_ovl07(EntFDC6C* e) {
    s32 r;
    u8* p;
    u16 y;
    s32 t;

    animate_object(e);
    move_object(e);
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

extern void (*D_80101E90_ovl07[])(Ovl07Ent*);

void func_800FDD28_ovl07(Ovl07Ent* e) {
    if (e->unk8E != 0 && ((Ovl07Ent*)e->unk7C)->unk8E == 2) {
        e->unk20 = -0x18000;
        e->unk24 = 0;
        e->unk8E = 0;
        e->unk5 = 6;
        e->unk6 = 0;
        return;
    }
    D_80101E90_ovl07[e->unk6](e);
}
