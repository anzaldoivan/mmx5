#include "types.h"
#include "mmx5/graphics.h"

void func_800EF4FC_ovl11(u8* obj) {
    obj[3] = 1;
    *(s16*)(obj + 0x54) = 0;
    obj[4]++;
    set_animation(obj, 3);
}
