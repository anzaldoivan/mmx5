#include "types.h"

#define G (*(u8**)0x1F80004C)

extern void func_80017248(u8*);

void func_800F5018_ovl26(u8* obj) {
    func_80017248(obj);
    if (G[0x97] == 0) {
        obj[6]++;
    }
}
