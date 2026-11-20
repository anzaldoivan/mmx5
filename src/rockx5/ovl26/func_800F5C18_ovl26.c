#include "types.h"
#include "mmx5/globals.h"

void func_800F5C18_ovl26(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        obj[5] = 4;
        obj[6] = 0;
    }
}
