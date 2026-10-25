#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8 D_800FAB2C_ovl09[];

void func_800F1AF8_ovl09(u8* obj) {
    if (*(s8*)(obj + 0x45) == 1) {
        *(u8**)(obj + 0x50) = D_800FAB2C_ovl09;
        func_800171E8(obj, 3);
        obj[5] = 5;
    }
}
