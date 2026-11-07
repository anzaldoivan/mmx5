#include "types.h"

extern void func_8002A600(s32, s32, s32);
extern void func_8004FD90(u8*, s32, s32, s32);
extern u16 D_8009A22C;
extern s32 D_8009A420;

void func_800FF374_ovl04(u8* arg0) {
    s32 s0;
    s32 s1;

    if (!(D_8009A420 & 7)) {
        s0 = *(s32*)(arg0 + 8);
        s1 = *(s32*)(arg0 + 0xC);
        func_8004FD90(arg0, 1, 0xFF, 0x1F);
        func_8004FD90(arg0, 1, 0xFF, 0x1F);
        func_8004FD90(arg0, 1, 0xFF, 0x1F);
        func_8004FD90(arg0, 1, 0xFF, 0x1F);
        *(s32*)(arg0 + 8) = s0;
        *(s32*)(arg0 + 0xC) = s1;
    }
    *(u16*)(arg0 + 0x7C) += 1;
    if (D_8009A22C == 0) {
        func_8002A600(0x30, 3, 2);
    }
    if (*(s16*)(arg0 + 0x7C) >= 0xB4) {
        arg0[5]++;
    }
}
