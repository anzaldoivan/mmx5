#include "types.h"

extern s32 func_8002DF78(void);
extern void func_8002D89C(u8*);
extern s32 D_800FE9A8_ovl06[];
extern s32 D_800FE9C8_ovl06[];

void func_800F6948_ovl06(u8* a0) {
    a0[3] = 1;
    if (((s8*)a0)[2] >= 8) {
        a0[0x47] = (func_8002DF78() & 3) + 9;
    } else {
        a0[0x47] = (func_8002DF78() & 3) + 4;
    }
    a0[0x16] = 1;
    *(s32*)(a0 + 0x2C) = 0x5000;
    *(s32*)(a0 + 0x20) = D_800FE9A8_ovl06[func_8002DF78() & 7];
    *(s32*)(a0 + 0x24) = D_800FE9C8_ovl06[func_8002DF78() & 7];
    a0[4]++;
    func_8002D89C(a0);
}
