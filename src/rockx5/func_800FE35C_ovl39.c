#include "types.h"

extern void func_80017248(u8* obj);

void func_800FE35C_ovl39(u8* obj) {
    func_80017248(obj);
    if (*(s8*)(obj + 0x45) == 0x10) {
        *(*(u8**)(obj + 0x7C) + 0x8B) = 1;
        obj[4] = 2;
    }
}
