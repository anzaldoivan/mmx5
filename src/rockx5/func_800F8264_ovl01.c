#include "types.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800F8264_ovl01(u8* obj) {
    func_800171E8(obj, 0);
    *(s16*)(obj + 0x7C) = 90;
    obj[6]++;
}
