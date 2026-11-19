#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

#define G D_1F80004C.bytes

void func_800F4FC0_ovl26(u8* obj) {
    animate_object(obj);
    if (G[0x97] == 1) {
        set_animation(obj, 6);
        obj[6]++;
    }
}
