#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F42C0_ovl26(u8* obj) {
    move_object(obj);
    animate_object(obj);
    if (*(s16*)(obj + 0xE) < 0x123D) {
        *(s32*)(obj + 0x24) = 0;
        obj[6]++;
        set_animation(obj, 0xF);
    }
}
