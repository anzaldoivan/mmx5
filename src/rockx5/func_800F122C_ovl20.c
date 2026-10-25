#include "types.h"

extern u8* func_8002D53C(void);
extern u8 D_800D1C00[];

void func_800F122C_ovl20(u8* arg0) {
    u8* base = D_800D1C00;
    u8* p;

    if (((s8*)base)[0x29] == 0) {
        p = func_8002D53C();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0xC;
            p[2] = 0x50;
        }
        base[0x29] = 1;
        arg0[2]++;
    }
}
