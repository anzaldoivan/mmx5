#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800F830C_ovl01(u8* obj) {
    func_800171E8(obj, 1);
    D_1F80004C.bytes[0x84] = 0;
    D_1F80004C.bytes[0x86] = 0;
    obj[6]++;
}
