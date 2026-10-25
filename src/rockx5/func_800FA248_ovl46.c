#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_8002C1C8(void);

extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern s32 D_80093DD8;

void func_800FA248_ovl46(u8* arg0) {
    if (++*(s16*)(arg0 + 4) == 30) {
        func_80016490(2, 0x4E, 0);
    }
    if (*(s16*)(arg0 + 4) == 50) {
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        func_8002C1C8();
        D_80093DD8 = 0xFFFF0000;
    }
}
