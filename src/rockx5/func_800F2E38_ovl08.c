#include "types.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800F2E38_ovl08(u8* obj) {
    *(u16*)(obj + 0x42) &= 0x7FFF;
    func_800171E8(obj, 1);
    obj[0x75] = 0;
    obj[6]++;
}
