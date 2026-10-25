/* Shared body (DK-5), from the banked draft of func_800F6AF0_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8003D29C(s32, s32);
extern void func_8002D9EC(Ent6AF0*, s32, s32);
extern u8 D_8009A0B5;

void DEDUP_NAME(Ent6AF0* e) {
    func_8003D29C(0x14, D_8009A0B5);
    e->unk5 = 1;
    e->unk47 = 0x35;
    e->unk7C = 0x7F;
    e->unk7E = 0x19;
    e->unk61 = 0x19;
    e->unk42 &= 0x7FFF;
    func_8002D9EC(e, 0x60, 0x60);
}
