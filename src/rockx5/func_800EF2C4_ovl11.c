#include "types.h"

extern void func_80017248(u8* obj);

void func_800EF2C4_ovl11(u8* obj) {
    func_80017248(obj);
    *(u16*)(obj + 0x80) += 1;
    if (*(s8*)(obj + 0x45) == 1) {
        obj[5] = 3;
    }
}
