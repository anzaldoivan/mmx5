#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void func_800F8338_ovl03(u8* obj) {
    if (obj[0x70] & 8) {
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        *(s16*)(obj + 0x7C) = 0;
        obj[6]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}
