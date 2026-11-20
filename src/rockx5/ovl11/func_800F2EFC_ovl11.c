#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F2EFC_ovl11(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x46) == 0) {
        set_animation(obj, 0xB);
        obj[6]++;
    }
}
