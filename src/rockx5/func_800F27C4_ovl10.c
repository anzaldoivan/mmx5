#include "types.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800F27C4_ovl10(u8* obj) {
    if (obj[0x90] == 0) {
        func_800171E8(obj, 11);
        obj[0x15] = 0x40;
    } else {
        func_800171E8(obj, 11);
        obj[0x15] = 0;
    }
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = -0x13000;
    obj[6]++;
}
