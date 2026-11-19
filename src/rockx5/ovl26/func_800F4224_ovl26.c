#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F4224_ovl26(u8* obj) {
    set_animation(obj, 0x19);
    animate_object(obj);
    obj[6]++;
}
