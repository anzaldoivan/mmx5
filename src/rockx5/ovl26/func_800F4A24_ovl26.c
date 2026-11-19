#include "types.h"
#include "mmx5/globals.h"

void func_800F4A24_ovl26(u8* obj) {
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        *(s16*)(obj + 0x7C) = 0x1E;
        obj[6]++;
    }
}
