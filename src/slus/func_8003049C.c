#include "types.h"

s32 func_80031430(u8* arg0, s16 arg1);
extern u8 D_800E9309;
extern u16 D_800E930A;
extern u16 D_800E930E;
extern u16 D_800E9312;
extern u16 D_800E931A;

s32 func_8003049C(u8* arg0) {
    s16 n;

    if (D_800E9309 & 1) {
        if (arg0[0x15] != 0) {
            n = D_800E9312 + D_800E931A + D_800E930E + D_800E930A - 1;
        } else {
            n = D_800E9312 + D_800E931A - D_800E930E + D_800E930A - 1;
        }
    } else {
        if (arg0[0x15] != 0) {
            n = D_800E9312 + D_800E931A + D_800E930E - D_800E930A;
        } else {
            n = D_800E9312 + D_800E931A - D_800E930E - D_800E930A;
        }
    }
    if (func_80031430(arg0, n) == 0) {
        s32 v = *(u16*)(arg0 + 0xA) + D_800E931A;
        *(u16*)(arg0 + 8) = 0;
        *(u16*)(arg0 + 0xA) = v;
        return 0;
    }
    return -1;
}
