#include "types.h"

extern s32 func_8002DF78(void);
extern void func_8004FF94(s32, s32, s32, s32);
extern u8 D_800E9588[];

void func_8004FD90(u8* p, s8 a1, u8 a2, u8 a3) {
    s16 x;
    s16 y;
    s32 n;

    a2 &= func_8002DF78();
    if (func_8002DF78() & 1) {
        x = *(u16*)(p + 0xA) + a2;
    } else {
        x = *(u16*)(p + 0xA) - a2;
    }
    a3 &= func_8002DF78();
    if (func_8002DF78() & 1) {
        y = *(u16*)(p + 0xE) + a3;
    } else {
        y = *(u16*)(p + 0xE) - a3;
    }
    n = D_800E9588[0] + 1;
    D_800E9588[0] = n;
    func_8004FF94(a1, x, y, (n & 1) ^ 1);
}
