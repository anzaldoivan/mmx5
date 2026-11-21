#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800FDDB4_ovl07(u8* obj) {
    *(s32*)(obj + 0x20) = -0x18000;
    *(s32*)(obj + 0x24) = 0;
    obj[6]++;
}

extern u8 D_80101DE0_ovl07[][8];

extern s32 func_800FEB48_ovl07(EntFE308*, s32);

void func_800FDDD4_ovl07(EntFE308* e) {
    s32 r;
    u16 u;
    s32 t;
    u8* p;

    animate_object(e);
    move_object(e);
    r = func_800FEB48_ovl07(e, 2);
    switch (r) {
    case 2:
        e->unk5 = D_80101DE0_ovl07[e->unk8C][6];
        e->unk6 = 0;
        break;
    case 1:
        u = D_80101DE0_ovl07[e->unk8C][2];
        e->unk6 = 0;
        e->unk5 = u;
        p = e->unk68;
        t = e->unkA;
        e->unkA = (-(e->unkA + (signed char)p[0] + p[2]) & 0xF) + t;
        break;
    }
}
