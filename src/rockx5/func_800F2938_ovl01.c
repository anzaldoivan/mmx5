#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 func_800F2F44_ovl01(u8* arg0);

void func_800F2938_ovl01(u8* obj) {
    func_800171E8(obj, 0);
    if (func_800F2F44_ovl01(obj) == 0) {
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0x20000;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0;
        obj[6]++;
    }
}
