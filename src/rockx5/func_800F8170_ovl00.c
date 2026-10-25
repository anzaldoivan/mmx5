#include "types.h"

extern u8* func_8002D27C(void);
extern s8 D_800D1C2E;

void func_800F8170_ovl00(u8* arg0) {
    u8* p;

    if (**(s8**)(arg0 + 0x80) == 0) {
        if (D_800D1C2E != 0) {
            arg0[6] += 3;
        } else {
            p = func_8002D27C();
            if (p != 0) {
                p[0] = 0x61;
                p[1] = 0x3A;
                *(u16*)(p + 0x40) = *(u16*)(arg0 + 0x40);
                *(s32*)(p + 0x3C) = *(s32*)(arg0 + 0x3C);
                *(u16*)(p + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
                arg0[6]++;
            }
        }
    }
}
