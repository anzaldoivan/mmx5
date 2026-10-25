#include "types.h"

extern void func_8002385C(s32, s32, s32);
extern u8 D_800D1F3C;
extern u8 D_8007C3B0[];
extern s8 D_8009A0A2;

void func_80055920(u8* obj) {
    if (D_800D1F3C == 2) {
        if (((s8*)obj)[2] == 8) {
            if (D_8009A0A2 < 0) {
                func_8002385C(0x55, 0xFF, 0);
            } else {
                func_8002385C(0x55, 0xFF, 0);
            }
        } else {
            func_8002385C(D_8007C3B0[((s8*)obj)[2]], 0xFF, 0);
        }
        obj[5]++;
    }
}
