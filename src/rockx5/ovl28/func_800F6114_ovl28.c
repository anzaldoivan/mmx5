#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F6114_ovl28(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (*(s32*)(obj + 0x24) <= 0) {
        set_animation(obj, 5);
        *(s8*)(obj + 0x67) = -1;
        obj[6]++;
    }
}
