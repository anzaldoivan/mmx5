#include "types.h"

extern void func_8003D29C(s32, s32);
extern void func_8002D9EC(Ent657C*, s32, s32);
extern u8 D_8009A0B5;

void func_800F9884_ovl00(Ent657C* e) {
    e->unk7C = 0x7F;
    e->unk7E = 0x19;
    e->unk61 = 0x19;
    e->unk42 &= 0x7FFF;
    e->unk5++;
    func_8003D29C(0x14, D_8009A0B5);
    func_8002D9EC(e, 0xFF, 0xFF);
}
