#include "types.h"

extern void func_8002385C(s32, s32, s32);
extern u8 D_800D1C00[];

void func_800F10E8_ovl07(u8* arg0) {
    u8* p;

    p = D_800D1C00;
    if (((s8*)p)[0x27] == 3) {
        if (((s8*)p)[0x26] == 8) {
            func_8002385C(0x38, 0xFF, 0);
        } else {
            func_8002385C(0x39, 0xFF, 0);
        }
        arg0[5]++;
    }
}
