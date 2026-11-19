#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "addr.h"

void func_800F2B0C_ovl01(u8* obj) {
    animate_object(obj);
    move_object(obj);
    if (--D_1F80004C.bytes[0x80] == 0xFF) {
        obj[5] = 4;
        obj[6] = 0;
    }
}
