#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern void func_800F6C74_ovl01(u8* obj, s32 state);

void func_800F68B8_ovl01(u8* obj) {
    if (*(s8*)(obj + 0x45) != 0) {
        if (*(s8*)(obj + 3) != 0) {
            func_800F6C74_ovl01(obj, 0);
        }
        obj[5] = 4;
        obj[6] = 0;
        set_animation(obj, 0);
    } else {
        animate_object(obj);
    }
}
