#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800F2A6C_ovl00(u8* obj) {
    set_animation(obj, 0x10);
    D_1F80004C.bytes[0x8A] = 2;
    obj[6]++;
}
