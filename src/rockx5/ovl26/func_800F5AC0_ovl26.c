#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

extern u8 D_800F9628_ovl26[];

void func_800F5AC0_ovl26(u8* obj) {
    if (D_1F80004C.bytes[0x92] == 0) {
        animate_object(obj);
        if ((s8)obj[0x45] == 1) {
            *(u8**)(obj + 0x50) = D_800F9628_ovl26;
            obj[0x60] = 0x20;
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x28) = 0;
            *(s32*)(obj + 0x24) = 0x2C000;
            *(s32*)(obj + 0x2C) = 0xD00;
            obj[6]++;
        }
    }
}
