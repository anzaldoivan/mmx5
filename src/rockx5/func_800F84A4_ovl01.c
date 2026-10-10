#include "types.h"

extern s32 func_800317B8(u8* a0);

void func_800F84A4_ovl01(u8* obj) {
    u8* p = *(u8**)(obj + 0x7C);

    if ((u8)(p[4] - 2) < 2) {
        obj[4]++;
    }
    obj[0x15] = p[0x15];
    *(u16*)(obj + 0xA) = *(u16*)(p + 0xA);
    *(u16*)(obj + 0xE) = *(u16*)(p + 0xE);
    func_800317B8(obj);
}
