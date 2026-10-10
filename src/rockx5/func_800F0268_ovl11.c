#include "types.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8*, s32);

void func_800F0268_ovl11(u8* obj) {
    func_80017248(obj);
    if (obj[0x87] != 0) {
        obj[0x87]--;
    } else {
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0x80000;
        obj[0x4] = 5;
        func_800171E8(obj, 3);
    }
}
