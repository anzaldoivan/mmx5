#include "types.h"

extern void func_80017248(u8* obj);

void func_800F56B4_ovl29(u8* obj) {
    func_80017248(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        obj[5] = 10;
        obj[6] = 0;
    }
}
