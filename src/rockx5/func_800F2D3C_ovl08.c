#include "types.h"

extern s32 func_80031DD0(u8* a0);
extern void func_80033024(u8* a0);
extern s32 func_8003240C(u8* a0);
extern void func_8003258C(u8* a0);
extern u8 D_8009A198;

void func_800F2D3C_ovl08(u8* a0) {
    s8 state = ((s8*)a0)[6];
    s8 r;

    if (state == 0) {
        a0[6]++;
        return;
    }
    if (state == 1) {
        r = func_80031DD0(a0);
        if (r < 0) {
            a0[5] = state;
            a0[6] = 0;
            return;
        }
        if (r > 0) {
            *(u16*)(a0 + 0x42) |= 0x8000;
        } else {
            *(u16*)(a0 + 0x42) &= 0x7FFF;
        }
        func_80033024(a0);
        if (D_8009A198 == 0) {
            func_8003240C(a0);
        }
        func_8003258C(a0);
    }
}
