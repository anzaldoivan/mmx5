#include "types.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800F9378_ovl28(u8* obj) {
    func_800171E8(obj, 2);
    obj[0x85] = 0x3C;
    if (((s8*)obj)[2] == 1) {
        obj[0x85] = 0x64;
    }
    obj[6]++;
}
