/* W27 draft: copy parent's 0x8000 flag, then clear it on a D_800D1C2A mask (rockx5 ovl04). */
#include "types.h"

extern u8 D_800D1C2A;
extern s32 func_800317B8(EntFEAC0*);
extern void func_8002D9EC(EntFEAC0*, s32, s32);

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
