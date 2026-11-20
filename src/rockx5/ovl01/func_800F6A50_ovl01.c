#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F6A50_ovl01(u8* obj) {
    if (*(signed char*)(obj + 0x45) != 0) {
        set_animation(obj, 3);
        obj[6]++;
    } else {
        *(u16*)(obj + 0x7C) -= 1;
        animate_object(obj);
    }
}
