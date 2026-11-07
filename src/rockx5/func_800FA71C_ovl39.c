#include "types.h"

extern void func_8002C218(void);
extern u8 D_800D50DC;
extern u8 D_8009A42C;
extern u8 D_80093E66;
extern s32 D_80093DD0[];

static inline void func_800FA71C_ovl39_clr_bit(s32 n) {
    s32 m = 1 << (31 - n % 32);

    D_80093DD0[n / 32] &= ~m;
}

void func_800FA71C_ovl39(u8* arg0) {
    s32 i;

    D_800D50DC = 1;
    D_8009A42C = 1;
    D_80093E66 = 1;
    func_8002C218();
    for (i = 0; i < 0x17; i++) {
        func_800FA71C_ovl39_clr_bit(i);
    }
    for (i = 0x1C; i < 0x3F; i++) {
        func_800FA71C_ovl39_clr_bit(i);
    }
    D_80093DD0[9] = -0x10;
    *(s16*)(arg0 + 0x7C) = 0;
    arg0[6]++;
}
