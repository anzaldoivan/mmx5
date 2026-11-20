#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern void func_800F6D48_ovl01(u8* obj);

void func_800F69E4_ovl01(u8* obj) {
    if (*(signed char*)(obj + 0x45) != 0) {
        func_800F6D48_ovl01(obj);
        obj[6]++;
        set_animation(obj, 4);
    } else {
        *(u16*)(obj + 0x7C) -= 1;
        animate_object(obj);
    }
}
