#include "types.h"
#include "mmx5/graphics.h"

extern void func_800F0978_ovl29(u8* obj);

void func_800F05A8_ovl29(u8* obj) {
    func_800F0978_ovl29(obj);
    if (obj[0x15] == 0) {
        *(s32*)(obj + 0x20) = -0x1CCCC;
    } else {
        *(s32*)(obj + 0x20) = 0x1CCCC;
    }
    set_animation(obj, 0);
    obj[6] = 1;
}
