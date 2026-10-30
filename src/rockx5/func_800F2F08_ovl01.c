#include "types.h"

extern void func_80017248(u8* obj);

void func_800F2F08_ovl01(u8* obj) {
    func_80017248(obj);
    if (*(s8*)(obj + 0x45) != 0) {
        obj[5] = 3;
        obj[6] = 0;
    }
}
