#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800FC85C_ovl07(u8* obj) {
    set_animation(obj, 4);
    D_1F80004C.bytes[0x8E] = 1;
    obj[6]++;
}

void func_800FC8A0_ovl07(u8* self) {
    if (--*(s16*)(self + 0x7C) == -1) {
        func_800FB030_ovl07(self);
    }
}
