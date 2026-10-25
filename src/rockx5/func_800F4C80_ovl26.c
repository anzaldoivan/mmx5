#include "types.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800F4C80_ovl26(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == 0) {
        func_800171E8(obj, 0xD);
        obj[6]++;
    }
}
