#include "types.h"
#include "addr.h"

#define G D_1F80004C.bytes
extern void func_80017248(u8*);
extern void func_800171E8(u8*, s32);

void func_800F4FC0_ovl26(u8* obj) {
    func_80017248(obj);
    if (G[0x97] == 1) {
        func_800171E8(obj, 6);
        obj[6]++;
    }
}
