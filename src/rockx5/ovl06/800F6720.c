#include "types.h"
#include "mmx5/globals.h"

extern void func_80032F70(u8* a0);
extern s32 func_800326BC(u8* a0);
extern s32 func_8003240C(u8* a0);
extern void func_8003258C(u8* a0);

void func_800F6720_ovl06(u8* a0) {
    s32 r;
    u16 v;
    s16 id;

    func_80032F70(a0);
    r = func_80033024(a0);
    v = *(u16*)(a0 + 0x42) & 0x7FFF;
    *(u16*)(a0 + 0x42) = v;
    if (r != 0) {
        id = *(s16*)(a0 + 0xA);
        if (id != 0x278 && id != 0x5A8) {
            *(u16*)(a0 + 0x42) = v | 0x8000;
            a0[0x5C]--;
        }
    }
    if (*(s8*)(a0 + 0x5C) == 0) {
        a0[4] = 3;
    }
    func_8002D9EC(a0, 0x30, 0x20);
    func_800326BC(a0);
    func_8003240C(a0);
    func_8003258C(a0);
}

extern s32 func_800326BC(u8* a0);
extern s32 func_8003240C(u8* a0);
extern void func_8003258C(u8* a0);
extern s16 D_8009A21C;

void func_800F67C4_ovl06(u8* a0) {
    s32 r;

    if (*(s8*)(a0 + 2) == 8) {
        D_8009A21C = 0x4F0;
    } else if (*(s8*)(a0 + 2) == 9) {
        D_8009A21C = 0x770;
    } else {
        D_8009A21C = 0xA00;
    }
    *(u16*)(a0 + 0x42) &= 0x7FFF;
    r = func_80031DD0(a0);
    func_8002D9EC(a0, 0x30, 0x20);
    if (r < 0) {
        *(s16*)(a0 + 0x80) = 0x3C;
        a0[4] = 4;
    } else {
        func_80033024(a0);
        func_800326BC(a0);
        func_8003240C(a0);
        func_8003258C(a0);
    }
}

void func_800F6880_ovl06(u8* a0) {
    if ((*(u16*)(a0 + 0x80) & 0xF) == 0) {
        func_8004FD90(a0, 1, 0x20, 0x20);
    }
    a0[3] ^= 1;
    if (a0[3] != 0) {
        func_8002D89C(a0);
    }
    if (*(s16*)(a0 + 0x80) == 0) {
        a0[4] = 3;
    } else {
        *(s16*)(a0 + 0x80) = *(s16*)(a0 + 0x80) - 1;
    }
    *(u16*)(a0 + 0x42) &= 0x7FFF;
}
