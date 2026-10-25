#include "types.h"

extern void func_80017248(u8* obj);

void func_800F6238_ovl26(u8* obj) {
    func_80017248(obj);
    if ((*(u8**)(obj + 0x7C))[0x93] == 0) {
        obj[4] = 2;
    }
}
