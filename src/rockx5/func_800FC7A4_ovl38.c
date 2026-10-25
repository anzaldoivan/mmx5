#include "types.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800FC7A4_ovl38(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == 0) {
        func_800171E8(obj, 0xE);
        *(s16*)(obj + 0x7C) = 50;
        obj[6]++;
    }
}
