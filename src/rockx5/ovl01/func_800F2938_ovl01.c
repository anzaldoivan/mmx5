#include "types.h"
#include "mmx5/graphics.h"

extern s32 func_800F2F44_ovl01(u8* arg0);

void func_800F2938_ovl01(u8* obj) {
    set_animation(obj, 0);
    if (func_800F2F44_ovl01(obj) == 0) {
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0x20000;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0;
        obj[6]++;
    }
}
