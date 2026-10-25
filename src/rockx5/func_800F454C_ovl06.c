#include "types.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800F454C_ovl06(u8* obj) {
    if (*(s8*)(obj + 0x45) != 0) {
        func_800171E8(obj, 2);
        obj[6] = 1;
    }
}
