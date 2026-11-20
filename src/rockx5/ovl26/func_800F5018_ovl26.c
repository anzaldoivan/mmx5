#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

#define G D_1F80004C.bytes

void func_800F5018_ovl26(u8* obj) {
    animate_object(obj);
    if (G[0x97] == 0) {
        obj[6]++;
    }
}
