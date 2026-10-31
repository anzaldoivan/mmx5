#include "types.h"

extern D_8009A1F8_t D_8009A1F8;
extern u8 D_800FEA3C_ovl28[];
extern u8 D_800FEA1C_ovl28[];
extern u16 D_800D50DE;
extern u16 D_8009A42E;
extern u16 D_80093E68;
extern void func_8002C1C8(void);
extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern s32 func_8002C338(s32, void*, s32);

void func_800EEE9C_ovl28(u8* arg0) {
    u8* p;

    if ((s16)(++*(s16*)(arg0 + 0x16) % 3) == 0) {
        p = (u8*)&D_8009A1F8;
        p[0xAB] = 1;
        D_800D50DE--;
        D_8009A42E -= 0x20;
        D_80093E68 -= 0x400;
        func_8002C3CC(D_800FEA3C_ovl28, D_800FEA1C_ovl28, 0x10,
                      0x1F - D_800D50DE, 0x1F);
        func_8002C338(0x47, D_800FEA3C_ovl28, 1);
        if (D_800D50DE == 0) {
            arg0[6]++;
            func_8002C1C8();
            p[0x57] = 0;
            func_8002C338(0x47, D_800FEA1C_ovl28, 1);
        }
    }
}
