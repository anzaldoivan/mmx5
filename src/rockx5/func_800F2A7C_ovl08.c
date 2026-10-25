#include "types.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800F2A7C_ovl08(u8* obj) {
    func_800171E8(obj, 10);
    obj[0x16] = 1;
    obj[0x3] = 1;
    obj[0x15] = 0;
    obj[0x4] = 1;
    obj[0x5] = 0;
    obj[0x6] = 0;
}
