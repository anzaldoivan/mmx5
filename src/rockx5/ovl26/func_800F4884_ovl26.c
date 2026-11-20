#include "types.h"
#include "mmx5/globals.h"

void func_800F4884_ovl26(u8* obj) {
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    animate_object(obj);
    obj[6]++;
}
