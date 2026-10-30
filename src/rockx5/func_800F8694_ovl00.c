#include "types.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800F8694_ovl00(u8* obj) {
    func_800171E8(obj, 0);
    obj[0x8F] = 0x5A;
    obj[6]++;
}
