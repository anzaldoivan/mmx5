#include "types.h"

extern void func_8004FD90(u8*, s32, s32, s32);
extern void func_8002A600(s32, s32, s32);
extern s32 func_8002DF78(void);
extern u8* func_8002D27C(void);
extern s32 D_8009A420;
extern u16 D_8009A22C;
extern u8 D_800D1C00[];
extern u8* D_8010308C_ovl04;

void func_800FD778_ovl04(u8* a0) {
    s32 x;
    s32 y;
    u8* p;

    *(s16*)(a0 + 0xE) += 1;
    if (!(D_8009A420 & 3)) {
        x = *(s32*)(a0 + 0x8);
        y = *(s32*)(a0 + 0xC);
        func_8004FD90(a0, 1, 0xFF, 0x1F);
        func_8004FD90(a0, 1, 0xFF, 0x1F);
        func_8004FD90(a0, 1, 0xFF, 0x1F);
        func_8004FD90(a0, 1, 0xFF, 0x1F);
        *(s32*)(a0 + 0x8) = x;
        *(s32*)(a0 + 0xC) = y;
    }
    if (*(s16*)(a0 + 0xE) < 0x137 && D_8009A22C == 0) {
        func_8002A600(0x10, 3, 2);
    }
    if (*(s16*)(a0 + 0xE) >= 0x140) {
        D_800D1C00[0x2A] |= 8;
        if (D_8010308C_ovl04 != 0) {
            D_8010308C_ovl04[4] = 2;
        }
        a0[5]++;
    }
    if (!(D_8009A420 & 7) && (func_8002DF78() & 0x10)) {
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x18;
            p[2] = 0;
            *(u8**)(p + 0x50) = a0;
        }
    }
}
