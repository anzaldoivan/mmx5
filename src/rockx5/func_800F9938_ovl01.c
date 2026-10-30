#include "types.h"

extern s32 func_8002DF78(void);
extern s32 func_8002D89C(u8*);
extern s32 D_800FDB9C_ovl01[];
extern s32 D_800FDBBC_ovl01[];

void func_800F9938_ovl01(u8* p) {
    p[3] = 1;
    p[0x16] = 1;
    *(s32*)(p + 0x2C) = 0x5000;
    p[0x47] = p[0x54];
    *(s32*)(p + 0x20) = D_800FDB9C_ovl01[func_8002DF78() & 7];
    *(s32*)(p + 0x24) = D_800FDBBC_ovl01[func_8002DF78() & 7];
    p[4]++;
    func_8002D89C(p);
    switch ((s8)p[2]) {
    case 1:
        *(s32*)(p + 0x24) = 0x60000;
        *(s32*)(p + 0x2C) = 0x4000;
        *(s32*)(p + 0x20) /= 2;
        *(s32*)(p + 0xC) += 0x200000;
        break;
    case 2:
        *(s32*)(p + 0x28) = 0;
        *(s32*)(p + 0x2C) = 0;
        *(s32*)(p + 0x20) *= 2;
        *(s32*)(p + 0xC) += 0x400000;
        break;
    case 3:
        *(s32*)(p + 0x24) = 0x60000;
        *(s32*)(p + 0xC) -= 0x100000;
        break;
    case 4:
        *(s32*)(p + 0x28) = 0;
        *(s32*)(p + 0x2C) = 0;
        *(s32*)(p + 0x20) *= 2;
        if (func_8002DF78() & 1) {
            *(s32*)(p + 0x24) = -*(s32*)(p + 0x24);
        }
        if (func_8002DF78() & 3) {
            *(s32*)(p + 0x20) *= 2;
        }
        break;
    case 5:
        *(s32*)(p + 0x20) /= 4;
        *(s32*)(p + 0x8) -= 0x400000;
        *(s32*)(p + 0xC) -= 0x400000;
        break;
    case 6:
        *(s32*)(p + 0x20) /= 4;
        *(s32*)(p + 0x8) += 0x400000;
        *(s32*)(p + 0xC) -= 0x400000;
        break;
    case 10:
        *(s32*)(p + 0x20) = 0;
        *(s32*)(p + 0x24) = 0;
        *(s32*)(p + 0x28) = 0;
        *(s32*)(p + 0x2C) = 0;
        p[0x16] = 6;
        p[0x54] = 0;
        p[0x55] = 0;
        p[3] = 0;
        break;
    }
}
