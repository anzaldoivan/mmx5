#include "types.h"

extern u8 D_800D1C00[];
extern u8 D_8009A0A0[];
extern u8 D_800F5F7F_ovl24;
extern u8 D_800F5F7A_ovl24;
extern u8 D_800F5F80_ovl24;
extern void func_8002C50C(void);
extern void func_8002D004(void);
extern void func_8002ACC4(void);
extern void func_8002906C(void);
extern s32 func_80027238(void);

void func_800EFFF8_ovl24(u8* a0) {
    D_800F5F7F_ovl24 = D_800D1C00[0x44];
    func_8002C50C();
    func_8002D004();
    func_8002ACC4();
    func_8002906C();
    func_80027238();
    a0[0xE] = 0;
    D_800D1C00[0x28] = 0;
    D_800F5F7A_ovl24 = 0;
    D_800F5F80_ovl24 = 0;
    D_8009A0A0[0xC9] = a0[0x4C];
    D_8009A0A0[2] = D_800F5F7F_ovl24;
    a0[2]++;
}
