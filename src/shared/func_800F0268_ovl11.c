#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F0268_ovl11(u8* obj) {
    animate_object(obj);
    if (obj[0x87] != 0) {
        obj[0x87]--;
    } else {
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0x80000;
        obj[0x4] = 5;
        set_animation(obj, 3);
    }
}
