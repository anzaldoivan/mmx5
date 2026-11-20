#include "types.h"
#include "mmx5/graphics.h"

void func_800F9378_ovl28(u8* obj) {
    set_animation(obj, 2);
    obj[0x85] = 0x3C;
    if (((s8*)obj)[2] == 1) {
        obj[0x85] = 0x64;
    }
    obj[6]++;
}
