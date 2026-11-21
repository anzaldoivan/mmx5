#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_8009A0B5;

void func_800F0C8C_ovl12(Ent657C* e) {
    set_animation(e, 0xA);
    e->unk7C = 0x7F;
    e->unk7E = 0x19;
    e->unk61 = 0x19;
    e->unk42 &= 0x7FFF;
    e->unk5++;
    func_8003D29C(0x14, D_8009A0B5);
    func_8002D9EC(e, 0xFF, 0xFF);
}
