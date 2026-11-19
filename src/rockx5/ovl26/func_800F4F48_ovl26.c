#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"
#include "addr.h"

void func_800F4F48_ovl26(u8* obj) {
    animate_object(obj);
    D_1F80004C.bytes[0x94] = (u32)random_byte() % 3 + 3;
    *(s16*)(obj + 0x7C) = 0;
    *(s16*)(obj + 0x7E) = 30;
    obj[7] = 0;
    obj[6]++;
}
