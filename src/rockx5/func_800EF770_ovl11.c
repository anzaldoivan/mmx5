#include "types.h"

extern u8 D_800D50DC;
extern u8 D_8009A42C;
extern u8 D_80093E66;
extern void func_8002C218(void);
extern void func_800EFC54_ovl11(s32);

void func_800EF770_ovl11(u8* arg0) {
    D_800D50DC = 0;
    D_8009A42C = 0;
    D_80093E66 = 0;
    func_8002C218();
    arg0[0x18] = 0;
    arg0[4]++;
    func_800EFC54_ovl11(1);
}
