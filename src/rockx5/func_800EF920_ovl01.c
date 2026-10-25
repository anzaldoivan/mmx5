#include "types.h"

extern s16 D_8009A256;
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern void func_80016490(s32, s32, void*);
extern u8* func_8002D144(void);
extern s32 func_8003D29C(s32, s32);
extern void func_8002C218(void);

void func_800EF920_ovl01(u8* arg0) {
    u8* p;
    u8 t;

    if (D_8009A256 >= 0xFD0) {
        func_80016490(0, 5, 0);
        p = func_8002D144();
        if (p != 0) {
            p[0] = 1;
            p[1] = 8;
        }
        func_8003D29C(0x1E, 0x40);
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        func_8002C218();
        t = arg0[5];
        arg0[0x19] = 4;
        arg0[0x1A] = 2;
        arg0[0x1B] = 0;
        arg0[5] = t + 1;
    }
}
