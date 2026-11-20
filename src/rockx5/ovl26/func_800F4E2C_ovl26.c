#include "types.h"
#include "mmx5/globals.h"

void func_800F4E2C_ovl26(u8* obj) {
    animate_object(obj);
    if (*(signed char*)(obj + 7) == 0x20) {
        obj[7] = 0;
        obj[6]++;
    }
}
