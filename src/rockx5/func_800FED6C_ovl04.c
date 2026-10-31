#include "types.h"

extern void func_8002A600(s32, s32, s32);
extern void func_8004FD90(u8*, s32, s32, s32);
extern s8 D_8009A0A5;
extern u16 D_8009A22C;
extern s32 D_8009A420;

void func_800FED6C_ovl04(u8* p) {
    s32 s1;
    s32 s0;

    if (!(D_8009A420 & 7)) {
        s1 = *(s32*)(p + 0x8);
        s0 = *(s32*)(p + 0xC);
        *(u16*)(p + 0xA) -= 0x10;
        *(u16*)(p + 0xE) += 8;
        func_8004FD90(p, 1, 0x1F, 0x7F);
        func_8004FD90(p, 1, 0x1F, 0x7F);
        func_8004FD90(p, 1, 0x1F, 0x7F);
        func_8004FD90(p, 1, 0x1F, 0x7F);
        *(s32*)(p + 0x8) = s1;
        *(s32*)(p + 0xC) = s0;
    }
    *(u16*)(p + 0x7C) += 1;
    if (D_8009A22C == 0) {
        func_8002A600(0x30, 3, 2);
    }
    if (*(s16*)(p + 0x7C) >= 0xB4 && D_8009A0A5 == 0x14) {
        p[5]++;
    }
}
