#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_8009A0B5;

void func_800FB550_ovl38(u8* obj) {
    func_8003D29C(0x14, D_8009A0B5);
    obj[5]++;
    *(u16*)(obj + 0x42) &= 0x7FFF;
    set_animation(obj, 0x13);
    *(s16*)(obj + 0x7C) = 0x7F;
    *(s16*)(obj + 0x7E) = 0x19;
    obj[0x61] = 0x19;
    func_8002D9EC(obj, 0x60, 0x60);
}
