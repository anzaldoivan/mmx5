#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void func_800F2D74_ovl01(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (*(s32*)(obj + 0x24) < 0) {
        obj[0x5] = 7;
        obj[0x6] = 0;
        *(s32*)(obj + 0x2C) = 0x5200;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s8*)(obj + 0x67) = -1;
    }
}
