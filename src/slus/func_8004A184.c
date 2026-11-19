#include "types.h"
#include "mmx5/globals.h"

void func_8004A184(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x46) == 0) {
        obj[3] = 0;
        obj[4] = 3;
    }
}
