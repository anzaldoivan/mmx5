#include "types.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800F1934_ovl10(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == -1) {
        func_800171E8(obj, 2);
        obj[6]++;
    }
}
