#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F68D4_ovl28(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (*(s32*)(obj + 0x24) <= 0) {
        obj[7] = 3;
        set_animation(obj, 9);
        *(s16*)(obj + 0x7C) = 0;
        *(s16*)(obj + 0x7E) = 0;
        obj[6]++;
    }
}
