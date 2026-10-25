#include "types.h"

extern void func_80017248(u8* obj);

void func_800F5068_ovl26(u8* obj) {
    func_80017248(obj);
    if (*(s8*)(obj + 7) == 0x20) {
        *(s16*)(obj + 0x7C) = 0x78;
        obj[6]++;
    }
}
