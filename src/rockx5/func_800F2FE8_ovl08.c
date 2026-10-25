#include "types.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800F2FE8_ovl08(u8* obj) {
    func_800171E8(obj, 4);
    obj[0x16] = 0x20;
    obj[3] = 0;
    obj[0x15] = 0;
    obj[4] = 1;
    obj[5] = 0;
    obj[6] = 0;
}
