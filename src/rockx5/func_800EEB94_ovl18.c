#include "types.h"

extern void func_8002C1C8(void);
extern u8 D_800D50DC;
extern u8 D_8009A42C;
extern u8 D_80093E66;
extern s32 D_80093DD0[];

void func_800EEB94_ovl18(u8* arg) {
    D_800D50DC = 1;
    D_8009A42C = 1;
    D_80093E66 = 1;
    func_8002C1C8();
    D_80093DD0[2] |= 0x4F000;
    arg[6]++;
    *(s16*)(arg + 0x16) = 0;
}
