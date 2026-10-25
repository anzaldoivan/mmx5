#include "types.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800F8360_ovl01(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == -1) {
        func_800171E8(obj, 3);
        obj[6]++;
    }
}
