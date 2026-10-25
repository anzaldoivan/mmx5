#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800F1AB0_ovl10(u8* obj) {
    if (((s8*)obj)[0x45] == 1 && D_1F80004C.bytes[0x80] == 0) {
        func_800171E8(obj, 5);
        obj[6]++;
    }
}
