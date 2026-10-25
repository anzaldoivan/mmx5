#include "types.h"

extern u8 D_800D50DC;
extern u8 D_8009A42C;
extern u8 D_80093E66;
extern void func_8002C218(void);
extern s32 func_8002CE20(s32, s32);

void func_800EF978_ovl11(u8* arg0) {
    D_800D50DC = 0;
    D_8009A42C = 0;
    D_80093E66 = 0;
    func_8002C218();
    arg0[0x18] = 0x3C;
    arg0[0x19] = 4;
    arg0[0x1E] = 0;
    arg0[0x1A] = 3;
    arg0[0x1B] = 0x78;
    func_8002CE20(2, 1);
    arg0[7] = 10;
    arg0[4]++;
}
