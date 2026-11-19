#include "types.h"
#include "mmx5/globals.h"

void func_800F56B4_ovl29(u8* obj) {
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        obj[5] = 10;
        obj[6] = 0;
    }
}
