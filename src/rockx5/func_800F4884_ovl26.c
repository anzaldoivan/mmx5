#include "types.h"

extern void func_80017248(u8* obj);

void func_800F4884_ovl26(u8* obj) {
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    func_80017248(obj);
    obj[6]++;
}
