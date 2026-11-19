#include "types.h"
#include "mmx5/globals.h"

void func_800F2AC0_ovl08(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) != 0) {
        obj[3] = 0;
        obj[4] = 2;
    }
}
