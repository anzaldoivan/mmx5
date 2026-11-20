#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800F1AB0_ovl10(u8* obj) {
    if (((s8*)obj)[0x45] == 1 && D_1F80004C.bytes[0x80] == 0) {
        set_animation(obj, 5);
        obj[6]++;
    }
}
