#include "types.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800F1330_ovl09(u8* obj) {
    func_800171E8(obj, 1);
    *(s16*)(obj + 0x7E) = 0x14;
    obj[6]++;
}
