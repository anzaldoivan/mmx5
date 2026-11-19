#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F8500_ovl29(u8* obj) {
    u8* parent = *(u8**)(obj + 0x50);

    *(s32*)(obj + 0x8) = *(s32*)(parent + 0x8);
    *(s32*)(obj + 0xC) = *(s32*)(parent + 0xC);
    animate_object(obj);
    func_8002D89C(obj);
    if (*(s8*)(parent + 0x67) == 0) {
        ((s32(*)())set_animation)(obj, 0x1A);
        obj[4] -= 2;
    } else {
        if (*(s8*)(obj + 0x46) < 0) {
            if (*(s8*)(obj + 0x2) != 0) {
                obj[4]--;
            }
        }
    }
}
