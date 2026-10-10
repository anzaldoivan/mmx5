#include "types.h"

extern void func_80017248(u8* obj);
extern u8 D_800FE198_ovl28[][3];

#define G (*(u8**)0x1F80004C)

void func_800F5F4C_ovl28(u8* obj) {
    func_80017248(obj);
    if ((signed char)obj[0x45] == 1) {
        obj[5] = D_800FE198_ovl28[0][++G[0x8A] + G[0x89] * 3];
        obj[6] = 0;
        obj[7] = 0;
    }
}
