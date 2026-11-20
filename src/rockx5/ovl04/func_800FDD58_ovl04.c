#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800D1C00[];

void func_800FDD58_ovl04(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x46) == 0) {
        if (*(s8*)(obj + 0x5) == 2) {
            set_animation(obj, 0);
        }
        obj[0x6] = 0;
        D_800D1C00[0x28] &= obj[0x95];
        D_800D1C00[0x29] &= obj[0x96];
    }
}
