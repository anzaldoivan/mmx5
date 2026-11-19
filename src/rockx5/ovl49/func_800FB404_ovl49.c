#include "types.h"

extern void func_8002C1C8(void);
extern u8 D_80091C44;
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern s32 D_80093DD0[];

void func_800FB404_ovl49(u8* a0) {
    s32 i;
    s32* p;
    s32 m;

    if (D_80091C44 == 0) {
        D_80093E66 = 1;
        D_8009A42C = 1;
        D_800D50DC = 1;
        func_8002C1C8();
        m = -1;
        p = D_80093DD0;
        p += 2;
        for (i = 0; i < 14; i++) {
            *p++ = m;
        }
        a0[1]++;
    }
}
