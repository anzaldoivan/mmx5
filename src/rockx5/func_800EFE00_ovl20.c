#include "types.h"

extern s32 func_8002C338(s32, void*, s32);
extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern u8 D_800D1C00[];
extern u8 D_800F5FF0_ovl20[];
extern u8 D_800F61F0_ovl20[];
extern u8 D_800F63F0_ovl20[];
extern u8 D_800F65F0_ovl20[];
extern u8 D_800F67F0_ovl20[];
extern u8 D_800F69F0_ovl20[];

void func_800EFE00_ovl20(u8* arg0) {
    u8* base;
    s32 k;
    s32 t;

    if (++*(s16*)(arg0 + 8) >= 2) {
        base = D_800D1C00;
        *(s16*)(arg0 + 8) = 0;
        t = base[0x27] - 1;
        base[0x27] = t;
        k = 0x1F;
        func_8002C3CC(D_800F61F0_ovl20, D_800F5FF0_ovl20, 0x100, k - (s8)t, k);
        func_8002C338(0x70, D_800F61F0_ovl20, 0x10);
        func_8002C3CC(D_800F65F0_ovl20, D_800F63F0_ovl20, 0x100,
                      k - *(s8*)(base + 0x27), k);
        func_8002C338(0xB0, D_800F65F0_ovl20, 0x10);
        func_8002C3CC(D_800F69F0_ovl20, D_800F67F0_ovl20, 0x100,
                      k - *(s8*)(base + 0x27), k);
        func_8002C338(0x40, D_800F69F0_ovl20, 0x10);
        if (*(s8*)(base + 0x27) == 0) {
            *(s32*)(arg0 + 0xAC) += 0xFFFCB440;
            arg0[2]++;
        }
    }
}
