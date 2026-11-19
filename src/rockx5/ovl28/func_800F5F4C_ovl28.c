#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

extern u8 D_800FE198_ovl28[][3];

#define G D_1F80004C.bytes
void func_800F5F4C_ovl28(u8* obj) {
    animate_object(obj);
    if ((signed char)obj[0x45] == 1) {
        obj[5] = D_800FE198_ovl28[0][++G[0x8A] + G[0x89] * 3];
        obj[6] = 0;
        obj[7] = 0;
    }
}
