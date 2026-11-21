#include "types.h"
#include "mmx5/globals.h"

void func_800F07B0_ovl01(u8* obj) {
    animate_object(obj);
    if ((u8)(obj[5] - 3) >= 2 && !(obj[0x70] & 8)) {
        obj[5] = 3;
        obj[6] = 0;
        *(s32*)(obj + 0x2C) = 0x3C00;
    }
}
