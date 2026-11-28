#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/system.h"

extern void func_8004FF94(s32, s32, s32, s32);
extern u8 D_800E9588[];

void func_8004FD90(u8* p, s32 arg1, s32 arg2, s32 arg3) {
    s8 a1 = arg1;
    u8 a2 = arg2;
    u8 a3 = arg3;
    s16 x;
    s16 y;
    s32 n;

    a2 &= random_byte();
    if (random_byte() & 1) {
        x = *(u16*)(p + 0xA) + a2;
    } else {
        x = *(u16*)(p + 0xA) - a2;
    }
    a3 &= random_byte();
    if (random_byte() & 1) {
        y = *(u16*)(p + 0xE) + a3;
    } else {
        y = *(u16*)(p + 0xE) - a3;
    }
    n = D_800E9588[0] + 1;
    D_800E9588[0] = n;
    func_8004FF94(a1, x, y, (n & 1) ^ 1);
}
