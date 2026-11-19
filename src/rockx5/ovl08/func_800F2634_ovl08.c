#include "types.h"

extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern u8 D_800F3F2C_ovl08[];

void func_800F2634_ovl08(u8* arg0) {
    u32 t;

    t = *(u32*)(arg0 + 0x7C);
    t++;
    *(u32*)(arg0 + 0x7C) = t;
    arg0[3] = arg0[0x7C] & 4;
    if (t >= 0x1F) {
        *(u16*)(arg0 + 0xA) += 8;
        *(u16*)(arg0 + 0xE) += 8;
        func_8004D4F4(5, D_800F3F2C_ovl08, arg0);
        t = 3;
        arg0[4] = t;
        arg0[3] = 0;
        *(u16*)(arg0 + 0xA) -= 8;
        *(u16*)(arg0 + 0xE) -= 8;
    }
}
