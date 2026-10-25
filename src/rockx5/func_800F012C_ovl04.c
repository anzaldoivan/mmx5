#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_8003D29C(s32, s32);
extern s8 D_8009A0A5;
extern s16 D_80102FD4_ovl04;
extern u8 D_800D1F20[];
extern u8 D_8009A296;

void func_800F012C_ovl04(u8* a0) {
    if (D_8009A0A5 == 0x14) {
        func_80016490(5, 10, 0);
        a0[0x1C] = 0;
        D_80102FD4_ovl04 = 0x100;
        a0[6]++;
        D_800D1F20[2] = 7;
        D_8009A296 = 8;
    } else if (D_8009A0A5 == 2) {
        func_8003D29C(0x14, 0x40);
    }
}
