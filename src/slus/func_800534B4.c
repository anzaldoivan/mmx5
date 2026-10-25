#include "types.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800534B4(u8* obj) {
    func_800171E8(obj, 2);
    if (obj[0x84] != 0) {
        *(s32*)(obj + 0x20) = 0x8000;
    } else {
        *(s32*)(obj + 0x20) = -0x8000;
    }
    obj[6]++;
}
