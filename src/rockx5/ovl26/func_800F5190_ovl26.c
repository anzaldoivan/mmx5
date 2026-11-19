#include "types.h"
#include "mmx5/globals.h"

void func_800F5190_ovl26(u8* obj) {
    animate_object(obj);
    if ((signed char)obj[7] == 0x10) {
        obj[7] = 0;
        obj[6]++;
    }
}
