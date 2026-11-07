#include "types.h"

extern u8 D_8009A1F8[];
extern u8 D_800FE178_ovl27[];
extern u8 D_800FE158_ovl27[];
extern u16 D_800D50DE;
extern u16 D_8009A42E;
extern u16 D_80093E68;
extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern s32 func_8002C338(s32, void*, s32);
extern void func_8002C1C8(void);

void func_800EF8AC_ovl27(u8* a0) {
    u8* p;
    u16 t;

    *(u16*)(a0 + 0x16) += 1;
    t = *(u16*)(a0 + 0x16);
    if (!(t & 1)) {
        p = D_8009A1F8;
        p[0xAB] = 1;
        D_800D50DE -= 1;
        D_8009A42E -= 0x20;
        D_80093E68 -= 0x400;
        func_8002C3CC(D_800FE178_ovl27, D_800FE158_ovl27, 0x10,
                      0x1F - D_800D50DE, 0x1F);
        func_8002C338(0x45, D_800FE178_ovl27, 1);
        if (D_800D50DE == 0) {
            *(u16*)(a0 + 0x16) = 0;
            a0[6]++;
            func_8002C1C8();
            p[0x57] = 0;
        }
    }
}
