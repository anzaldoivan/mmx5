#include "types.h"

extern s32 func_80031DD0(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_80033024(u8* a0);
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
