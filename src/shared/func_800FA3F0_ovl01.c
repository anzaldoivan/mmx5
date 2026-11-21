#include "types.h"
#include "mmx5/globals.h"

void func_800FA3F0_ovl01(u8* obj) {
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        obj[5] = 3;
        obj[6] = 0;
    }
}
