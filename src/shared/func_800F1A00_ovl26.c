#include "types.h"
#include "mmx5/globals.h"

void func_800F1A00_ovl26(u8* obj) {
    *(u16*)(obj + 0x42) &= 0x7FFF;
    animate_object(obj);
    if (*(signed char*)(obj + 0x45) != 0) {
        obj[4] = 2;
    }
}
