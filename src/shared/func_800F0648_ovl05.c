#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800F0648_ovl05(u8* obj) {
    D_1F80004C.bytes[0x86] = 0;
    set_animation(obj, 6);
    obj[6]++;
}
