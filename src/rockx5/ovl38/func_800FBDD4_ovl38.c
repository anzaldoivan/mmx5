#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

void func_800FBDD4_ovl38(u8* obj) {
    animate_object(obj);
    D_1F80004C.bytes[0x8D] = 1;
    obj[5] = 3;
    obj[6] = 0;
}
