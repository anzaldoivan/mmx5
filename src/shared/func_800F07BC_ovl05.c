#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800F07BC_ovl05(u8* obj) {
    set_animation(obj, 10);
    D_1F80004C.bytes[0x86] = 0;
    obj[6]++;
}
