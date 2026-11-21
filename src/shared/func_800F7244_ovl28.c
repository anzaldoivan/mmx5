#include "types.h"
#include "mmx5/globals.h"

void func_800F7244_ovl28(u8* obj) {
    animate_object(obj);
    if (*(signed char*)(obj + 0x45) == 1) {
        obj[4]++;
    }
}
