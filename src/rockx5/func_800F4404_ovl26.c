#include "types.h"

extern void func_80017248();

void func_800F4404_ovl26(u8* o) {
    func_80017248();
    *(s16*)(o + 0x7C) = 0x3C;
    o[6]++;
}
