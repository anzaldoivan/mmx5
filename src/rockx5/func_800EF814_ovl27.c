#include "types.h"

extern u8 D_800D1C00[];
extern u8 D_800FE178_ovl27[];
extern u8 D_800FE158_ovl27[];
extern u16 D_800D50DE;
extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern s32 func_8002C338(s32, void*, s32);

void func_800EF814_ovl27(u8* a0) {
    u8* p = D_800D1C00;

    if (((s8*)p)[0x27] != 0 && ((s8*)p)[0x2A] != 0) {
        func_8002C3CC(D_800FE178_ovl27, D_800FE158_ovl27, 0x10,
                      0x1F - D_800D50DE, 0x1F);
        func_8002C338(0x45, D_800FE178_ovl27, 1);
        a0[6]++;
    }
}
