#include "types.h"

extern s32 func_800312A8(u8* arg0, s16 arg1, s32 arg2);
extern u8 D_800E9309;
extern s16 D_800E930C;
extern s16 D_800E9310;
extern u16 D_800E9314;
extern u16 D_800E931C;

s32 func_800311CC(u8* arg0) {
    s32 flag;
    s16 y;
    s32 e;

    if (D_800E9309 & 4) {
        s32 t = D_800E9314 + D_800E931C;
        flag = 0;
        y = D_800E9310 + t - D_800E930C;
    } else {
        s32 t = D_800E9314 + D_800E931C;
        flag = 1;
        y = D_800E9310 + t + D_800E930C - 1;
    }
    if (func_800312A8(arg0, y, flag) != 0) {
        return -1;
    }
    e = *(u16*)(arg0 + 0xE) + D_800E931C;
    *(u16*)(arg0 + 0xC) = 0;
    *(u16*)(arg0 + 0xE) = e;
    return 0;
}
