#include "types.h"

extern void func_8002DED4(u8* obj);

void func_800F1A88_ovl04(u8* obj) {
    Fix0418
        d; // the s32 view keeps the pair in a register; only the high half is used

    func_8002DED4(obj);
    if (*(s32*)(obj + 0x24) < 0) {
        d.h.hi = *(u16*)(obj + 0xE) - *(u16*)(obj + 0x86);
    } else {
        d.h.hi = *(u16*)(obj + 0x86) - *(u16*)(obj + 0xE);
    }
    if (d.h.hi >= 0x30) {
        *(u16*)(obj + 0x86) = *(u16*)(obj + 0xE);
        *(s32*)(obj + 0x2C) = -*(s32*)(obj + 0x2C);
        obj[0x81]++;
    }
}
