#include "types.h"

extern s32 func_800EF450_ovl10(u8* arg);
extern s32 func_800EF494_ovl10(u8* arg);
extern void func_800171E8(u8* obj, s32 state);

void func_800EF2D0_ovl10(u8* obj, u8* arg) {
    if (func_800EF450_ovl10(arg)) {
        func_800171E8(obj, 0x13);
        obj[3] = 1;
        obj[5] = 1;
    } else if (func_800EF494_ovl10(arg)) {
        func_800171E8(obj, 0x14);
        obj[3] = 1;
        obj[5] = 2;
    }
}
