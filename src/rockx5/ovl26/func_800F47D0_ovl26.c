#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

void func_800F47D0_ovl26(u8* obj) {
    animate_object(obj);
    if (D_1F80004C.bytes[0x92] == 0) {
        obj[5] = 4;
        obj[6] = 0;
    }
}
