#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F52AC_ovl26(u8* obj) {
    animate_object(obj);
    set_animation(obj, 0x11);
    obj[6]++;
}
