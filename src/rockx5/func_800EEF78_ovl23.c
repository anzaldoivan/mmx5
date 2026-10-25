#include "types.h"

extern signed char D_8009A424;
extern u8 D_8009A1F8[];
extern s32 func_8001E668(void);
extern s32 func_8002C50C(void);

void func_800EEF78_ovl23(u8* a0) {
    if (D_8009A424 == 0) {
        func_8001E668();
        D_8009A1F8[3] = 0;
        D_8009A1F8[0x57] = 0;
        D_8009A1F8[0xAB] = 0;
        func_8002C50C();
        if (a0[0x79] == 0) {
            a0[0] = 0x13;
            a0[0x1D] = 0;
        } else {
            a0[0xC] = 0x16;
            a0[0xD] = 0;
            a0[0] = 7;
        }
        a0[1] = 0;
        a0[2] = 0;
        a0[3] = 0;
    }
}
