#include "types.h"

extern void func_80017248(u8* obj);

void func_800F4C3C_ovl26(u8* obj) {
    func_80017248(obj);
    if (*(signed char*)(obj + 0x45) != 0) {
        *(s16*)(obj + 0x7C) = 0x3C;
        obj[6]++;
    }
}
