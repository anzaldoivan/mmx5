/* Shared body (DK-5), from the banked draft of func_800F95C8_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(Ent657C*, s32);
extern void func_8003D29C(s32, s32);
extern void func_8002D9EC(Ent657C*, s32, s32);
extern u8 D_8009A0A0[];

void DEDUP_NAME(Ent657C* e) {
    ((u8*)e)[0x9A] = 0;
    D_8009A0A0[0xCA] = 0;
    func_8003D29C(0x14, D_8009A0A0[0x15]);
    e->unk5 = 1;
    e->unk42 &= 0x7FFF;
    func_800171E8(e, 4);
    e->unk7C = 0x7F;
    e->unk7E = 0x19;
    e->unk61 = 0x19;
    func_8002D9EC(e, 0x60, 0x60);
}
