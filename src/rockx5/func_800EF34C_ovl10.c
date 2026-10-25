#include "types.h"

extern s32 func_800EF450_ovl10(u8* arg);
extern s32 func_800EF494_ovl10(u8* arg);
extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void func_800EF34C_ovl10(u8* obj, u8* arg) {
    if (func_800EF450_ovl10(arg)) {
        func_80017248(obj);
        obj[3] = 1;
    } else if (func_800EF494_ovl10(arg)) {
        func_800171E8(obj, 0x14);
        obj[3] = 1;
        obj[5] = 2;
    } else {
        obj[3] = 0;
        obj[5] = 0;
    }
}
