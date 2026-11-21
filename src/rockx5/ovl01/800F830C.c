#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800F830C_ovl01(u8* obj) {
    set_animation(obj, 1);
    D_1F80004C.bytes[0x84] = 0;
    D_1F80004C.bytes[0x86] = 0;
    obj[6]++;
}

void func_800F8360_ovl01(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == -1) {
        set_animation(obj, 3);
        obj[6]++;
    }
}
