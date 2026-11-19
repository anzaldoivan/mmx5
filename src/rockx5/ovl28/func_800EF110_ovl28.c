#include "types.h"

extern void func_8002C1C8(void);
extern u8 D_800D50DC;
extern u8 D_8009A42C;
extern u8 D_80093E66;
extern s32 D_80093DD0[];

void func_800EF110_ovl28(u8* arg) {
    s32 i;

    D_800D50DC = 1;
    D_8009A42C = 1;
    D_80093E66 = 1;
    func_8002C1C8();
    for (i = 8; i < 12; i++) {
        s32 bit = i + 0x40;
        s32 q = bit / 32;
        s32 sh = 31 - (bit - q * 32);
        s32 m = 1 << sh;
        D_80093DD0[q] |= m;
    }
    arg[6]++;
    *(s16*)(arg + 0x16) = 0;
}
