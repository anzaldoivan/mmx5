#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800F9628_ovl26[];

void func_800F4260_ovl26(u8* obj) {
    animate_object(obj);
    if (((s8*)obj)[0x45] == 1) {
        *(s32*)(obj + 0x54) = 0;
        *(u8**)(obj + 0x50) = D_800F9628_ovl26;
        set_animation(obj, 7);
        *(s32*)(obj + 0x24) = 0x40000;
        obj[6]++;
    }
}
