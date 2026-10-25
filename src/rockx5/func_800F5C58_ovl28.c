#include "types.h"

extern void func_80017248(u8* obj);

void func_800F5C58_ovl28(u8* o) {
    func_80017248(o);
    if (*(s8*)(o + 0x45) == 1) {
        o[5] = 7;
        o[6] = 0;
        o[7] = 0;
    }
}
