#include "types.h"

extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern s32 func_8002C338(s32, void*, s32);
extern u8 D_8009A2A3;
extern u8 D_800FDC18_ovl27[];
extern u8 D_800FDC98_ovl27[];
extern u8 D_800FDD18_ovl27[];
extern u8 D_800FDD38_ovl27[];
extern u8 D_800FDD58_ovl27[];
extern u8 D_800FDF58_ovl27[];
extern u8 D_800FE158_ovl27[];

void func_800EF360_ovl27(u8* a0) {
    s16 t;

    t = ++*(s16*)(a0 + 0x16);
    if ((s16)(t % 2) * 20 == 0) {
        a0[0x1C]++;
        func_8002C3CC(D_800FDF58_ovl27, D_800FDD58_ovl27, 0x100,
                      0x1F - a0[0x1C], 0x1F);
        func_8002C338(0x50, D_800FDF58_ovl27, 0x10);
        func_8002C3CC(D_800FDC98_ovl27, D_800FDC18_ovl27, 0x40, 0x1F - a0[0x1C],
                      0x1F);
        func_8002C338(*(s16*)(a0 + 0x1A), D_800FDC98_ovl27, 4);
        func_8002C3CC(D_800FDD38_ovl27, D_800FDD18_ovl27, 0x10, a0[0x1C], 0x1F);
        func_8002C338(0x46, D_800FDD38_ovl27, 1);
        if (a0[0x1C] >= 0x1F) {
            a0[6]++;
            D_8009A2A3 = 0;
            func_8002C338(0x50, D_800FDD58_ovl27, 0x10);
            func_8002C338(*(s16*)(a0 + 0x1A), D_800FDC18_ovl27, 4);
            func_8002C338(0x46, D_800FDD18_ovl27, 1);
            func_8002C338(0x45, D_800FE158_ovl27, 1);
        }
    }
}
