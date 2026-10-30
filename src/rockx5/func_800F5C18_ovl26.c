#include "types.h"

extern void func_80017248(u8* obj);

void func_800F5C18_ovl26(u8* obj) {
    func_80017248(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        obj[5] = 4;
        obj[6] = 0;
    }
}
