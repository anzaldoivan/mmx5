#include "types.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800F2A90_ovl10(u8* obj) {
    if (obj[0x90] == 0) {
        func_800171E8(obj, 9);
        obj[0x15] = 0;
    } else {
        func_800171E8(obj, 9);
        obj[0x15] = 0;
    }
    *(s32*)(obj + 0x20) = 0x13000;
    *(s32*)(obj + 0x24) = 0;
    obj[6]++;
}
