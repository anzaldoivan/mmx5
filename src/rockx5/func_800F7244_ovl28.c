#include "types.h"

extern void func_80017248(u8* obj);

void func_800F7244_ovl28(u8* obj) {
    func_80017248(obj);
    if (*(signed char*)(obj + 0x45) == 1) {
        obj[4]++;
    }
}
