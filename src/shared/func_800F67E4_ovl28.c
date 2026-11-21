#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F67E4_ovl28(u8* obj) {
    animate_object();
    set_animation(obj, 1);
    obj[6]++;
}
