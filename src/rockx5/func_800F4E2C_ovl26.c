#include "types.h"

extern void func_80017248(u8* obj);

void func_800F4E2C_ovl26(u8* obj) {
    func_80017248(obj);
    if (*(signed char*)(obj + 7) == 0x20) {
        obj[7] = 0;
        obj[6]++;
    }
}
