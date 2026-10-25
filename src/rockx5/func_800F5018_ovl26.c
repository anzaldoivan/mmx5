#include "types.h"
#include "addr.h"

#define G D_1F80004C.bytes
extern void func_80017248(u8*);

void func_800F5018_ovl26(u8* obj) {
    func_80017248(obj);
    if (G[0x97] == 0) {
        obj[6]++;
    }
}
