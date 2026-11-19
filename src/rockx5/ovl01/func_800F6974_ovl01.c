#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F6974_ovl01(u8* obj) {
    animate_object(obj);
    if (D_8009A0AA < *(s16*)(obj + 0xA) + 8 && *(signed char*)(obj + 3) != 0) {
        *(s16*)(obj + 0x7C) = 0x78;
        set_animation(obj, 5);
        obj[6]++;
    }
}
