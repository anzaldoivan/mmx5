#include "types.h"
#include "mmx5/globals.h"

void func_800FEA28_ovl04(u8* a0) {
    u8* child = *(u8**)(a0 + 0x80);
    u8* g;

    if (func_80031DD0(a0) != 0) {
        g = g_playthrough_state.u;
        g[0x27] |= 1;
    }
    *(u16*)(a0 + 0x42) &= 0x7FFF;
    func_800317B8(a0);
    func_8002D9EC(a0, 0x40, 0x20);
    if (*(s8*)(child + 5) >= 4) {
        a0[5]++;
    }
}

extern u8 D_800D1C2A;

void func_800FEAC0_ovl04(EntFEAC0* o) {
    EntFEAC0* p = o->unk80;
    s32 mask;

    func_800317B8(o);
    func_8002D9EC(o, 0x40, 0x20);
    if (p->unk42 & 0x8000) {
        o->unk42 |= 0x8000;
    } else {
        o->unk42 &= 0x7FFF;
    }
    mask = 2;
    if (o->unk2 == 10) {
        mask = 1;
    }
    if (D_800D1C2A & mask) {
        o->unk42 &= 0x7FFF;
        o->unk5++;
    }
}

#define func_800FE228_ovl04 func_800FEB78_ovl04
#include "shared/func_800FE228_ovl04.c"
#undef func_800FE228_ovl04
