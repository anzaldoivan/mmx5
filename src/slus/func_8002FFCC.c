#include "types.h"

extern s32 func_80030BB4(u8* arg0, s16 x, s16 y);
extern s32 func_80030F40(u8* arg0, s32 arg1);
extern s16 D_800E930A;
extern s16 D_800E930C;
extern s16 D_800E9316;
extern s16 D_800E9318;

void func_8002FFCC(u8* arg0) {
    s16 x;
    s32 r;

    x = D_800E9316 + D_800E930A - 1;
    if (func_80030F40(arg0, func_80030BB4(arg0, x, D_800E9318)) != 0) {
        return;
    }
    if (arg0[0x71] & 8) {
        r = func_80030BB4(arg0, x, D_800E9318 - D_800E930C - 1);
    } else {
        r = func_80030BB4(arg0, x, D_800E9318 - D_800E930C);
    }
    if (func_80030F40(arg0, r) != 0) {
        return;
    }
    func_80030F40(arg0, func_80030BB4(arg0, x, D_800E9318 + D_800E930C - 1));
}
