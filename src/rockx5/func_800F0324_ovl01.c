#include "types.h"

extern void func_80017248(u8* obj);

void func_800F0324_ovl01(u8* obj) {
    func_80017248(obj);
    if (*(s8*)(obj + 0x45) != 0) {
        *(s16*)(obj + 0x7C) = 10;
        obj[6] = 1;
    }
}
