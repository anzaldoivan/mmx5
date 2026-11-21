#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern void silence_sound(s32, s32);
extern u8 D_8009A0B5;

void func_800F657C_ovl09(Ent657C* e) {
    silence_sound(2, 0x26);
    set_animation(e, 2);
    e->unk7C = 0x7F;
    e->unk7E = 0x19;
    e->unk61 = 0x19;
    e->unk42 &= 0x7FFF;
    e->unk5++;
    func_8003D29C(0x14, D_8009A0B5);
    func_8002D9EC(e, 0xFF, 0xFF);
}
