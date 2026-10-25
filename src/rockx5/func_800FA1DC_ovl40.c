#include "types.h"

extern void func_8002C1C8(void);

extern u8 D_80091C44;
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern s32 D_80093DD8;

void func_800FA1DC_ovl40(u8* arg0) {
    if (D_80091C44 == 0) {
        D_80093E66 = 1;
        D_8009A42C = 1;
        D_800D50DC = 1;
        func_8002C1C8();
        D_80093DD8 = 0xFFFF0000;
        arg0[1]++;
    }
}
