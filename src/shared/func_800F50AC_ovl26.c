#include "types.h"
#include "mmx5/globals.h"

void func_800F50AC_ovl26(u8* obj) {
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        obj[7] = 0;
        obj[6]++;
    }
}
