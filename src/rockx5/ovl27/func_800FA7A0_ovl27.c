#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern void func_800FAE20_ovl27(u8* obj, s32 arg);

void func_800FA7A0_ovl27(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == 0) {
        set_animation(obj, 8);
        D_1F80004C.bytes[0x8A] = 1;
        func_800FAE20_ovl27(obj, 0x400);
        func_800FAE20_ovl27(obj, 0xC00);
        *(s16*)(obj + 0x7C) = 60;
        *(s16*)(obj + 0x7E) = 3;
        obj[6]++;
    }
}
