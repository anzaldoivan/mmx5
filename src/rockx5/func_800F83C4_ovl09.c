#include "types.h"

void func_8003D29C(s32, s32);
void func_80028B18(s32, s32, s32, void*);
extern u8 D_8009A0A0[];
extern s16 D_8009A202;
extern u8 D_800D1C00[];
extern u8 D_800FB47C_ovl09[];

void func_800F83C4_ovl09(u8* arg0) {
    u8* p = D_8009A0A0;

    if (*(s8*)(p + 5) == 0x14) {
        if (*(s16*)(p + 0xA) - D_8009A202 < 0xA0) {
            func_8003D29C(0x1D, 0x40);
        } else {
            func_8003D29C(0x1D, 0);
        }
        func_80028B18(0, 0x660, 0x870, D_800FB47C_ovl09);
        func_80028B18(0, 0x6B0, 0x870, D_800FB47C_ovl09 + 8);
        func_80028B18(0, 0x700, 0x870, D_800FB47C_ovl09 + 0x10);
        func_80028B18(0, 0x750, 0x870, D_800FB47C_ovl09 + 0x18);
        *(s16*)(arg0 + 0x7C) = 0xB4;
        D_800D1C00[0x24] = 0;
        *(s32*)(D_800D1C00 + 0x20) = 0;
        arg0[5]++;
    }
}
