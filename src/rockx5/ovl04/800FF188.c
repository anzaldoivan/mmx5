#include "types.h"
#include "mmx5/globals.h"

void func_800FF188_ovl04(u8* arg0) {
    if (((s8*)*(u8**)(arg0 + 0x80))[5] >= 4) {
        arg0[5]++;
    }
}

extern u8 D_800D1C2A;

void func_800FF1BC_ovl04(EntFEAC0* o) {
    EntFEAC0* p = o->unk80;

    func_800317B8(o);
    func_8002D9EC(o, 0x40, 0x20);
    if (p->unk42 & 0x8000) {
        o->unk42 |= 0x8000;
    } else {
        o->unk42 &= 0x7FFF;
    }
    if (D_800D1C2A & 4) {
        o->unk42 &= 0x7FFF;
        o->unk5++;
    }
}

#define func_800FE228_ovl04 func_800FF260_ovl04
#include "shared/func_800FE228_ovl04.c"
#undef func_800FE228_ovl04
