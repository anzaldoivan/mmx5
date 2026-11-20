#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800F8C7C_ovl09(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == 0) {
        D_1F80004C.bytes[0x86] = 0;
        set_animation(obj, 0xD);
        obj[5] = 4;
        obj[6] = 0;
    }
}
