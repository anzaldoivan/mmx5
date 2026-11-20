#include "types.h"
#include "mmx5/globals.h"

void func_800F2F08_ovl01(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) != 0) {
        obj[5] = 3;
        obj[6] = 0;
    }
}
