#include "types.h"
#include "addr.h"

extern u8 D_800FE198_ovl28[][3];

#define G D_1F80004C.bytes
void func_800F59AC_ovl28(u8* obj) {
    if ((signed char)obj[0x45] == 1) {
        obj[5] = D_800FE198_ovl28[0][++G[0x8A] + G[0x89] * 3];
        obj[6] = 0;
    }
    if (obj[0x15]) {
        *(s32*)(obj + 0x20) = 0x42000;
    } else {
        *(s32*)(obj + 0x20) = -0x42000;
    }
    *(s32*)(obj + 0x28) = -0x3000;
    *(s8*)(obj + 0x9A) = -1;
    obj[6]++;
}
