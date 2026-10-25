#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern u8 D_800FE198_ovl28[][3];

#define G D_1F80004C.bytes
void func_800F6580_ovl28(u8* obj) {
    func_80017248(obj);
    if (G[0x8C] == 1) {
        obj[5] = D_800FE198_ovl28[0][++G[0x8A] + G[0x89] * 3];
        obj[6] = 0;
        obj[7] = 0;
    }
}
