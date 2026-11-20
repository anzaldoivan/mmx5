#include "types.h"
#include "mmx5/system.h"
#include "addr.h"

void func_800F4014_ovl26(u8* obj) {
    D_1F80004C.bytes[0x94] = (u32)random_byte() % 3;
    *(s16*)(obj + 0x7C) = 0;
    *(s16*)(obj + 0x7E) = 1;
    obj[6]++;
}
