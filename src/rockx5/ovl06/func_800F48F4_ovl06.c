#include "types.h"
#include "mmx5/movement.h"

void func_800F48F4_ovl06(u8* obj) {
    apply_object_motion(obj);
    if (*(s32*)(obj + 0x20) > 0) {
        *(s16*)(obj + 0x7C) = 0x14;
        obj[6]++;
    }
}
