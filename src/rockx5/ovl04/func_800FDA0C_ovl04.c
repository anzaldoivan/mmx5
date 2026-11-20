#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void func_800FDA0C_ovl04(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (*(s32*)(obj + 0x20) >= -0x10000) {
        *(s32*)(obj + 0x20) = -0x10000;
    }
}
