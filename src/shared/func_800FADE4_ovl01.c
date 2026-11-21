#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800FADE4_ovl01(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        set_animation(obj, 0xC);
        obj[6] = 5;
    }
}
