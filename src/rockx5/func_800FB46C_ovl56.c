#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern void func_8002C1C8(void);
extern u8 D_80091C44;
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern s32 D_80093DD0[];

void func_800FB46C_ovl56(u8* arg) {
    if (D_80091C44 == 0) {
        func_80016490(2, 0x55, 0);
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        func_8002C1C8();
        D_80093DD0[5] = 0xFFFF;
        D_80093DD0[6] = 0xFFFF0000;
        arg[1]++;
        *(s16*)(arg + 6) = 0;
    }
}
