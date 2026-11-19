#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F6694_ovl28(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 7) == 2) {
        set_animation(obj, 10);
        *(s16*)(obj + 0x7C) = 0;
        *(s16*)(obj + 0x7E) = 5;
        obj[6]++;
    }
}
