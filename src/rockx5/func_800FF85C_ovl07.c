#include "types.h"

extern void func_8004FD90(u8*, s32, s32, s32);
extern void func_80028B18(s32, s32, s32, void*);
extern u8 D_8009A244;
extern u8 D_800D1C00[];
extern u8 D_80101FBC_ovl07[];

void func_800FF85C_ovl07(u8* arg0) {
    s32 t;
    u8* p;

    *(u16*)(arg0 + 0x42) &= 0x7FFF;
    t = arg0[0x55] + 1;
    arg0[0x55] = t;
    if ((s8)t == 20) {
        func_8004FD90(arg0, 1, 0, 0x30);
        func_8004FD90(arg0, 1, 0, 0x30);
        func_8004FD90(arg0, 1, 0, 0x30);
        func_8004FD90(arg0, 1, 0, 0x30);
    } else if ((s8)t == 24) {
        func_80028B18(0, 0x1F20, 0x80, D_80101FBC_ovl07);
        D_8009A244 = 1;
    } else if ((s8)t == 44) {
        p = D_800D1C00;
        p[0x27] |= 1;
        arg0[4]++;
    }
}
