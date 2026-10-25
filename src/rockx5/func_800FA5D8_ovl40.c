#include "types.h"

extern signed char D_8009A424;
extern u8 D_8009A1F8[];
extern void func_8001E668(void);
extern void func_8002C50C(void);

void func_800FA5D8_ovl40(u8* a0) {
    s32 i;
    u8* p;

    if (D_8009A424 == 0) {
        func_8001E668();
        p = D_8009A1F8;
        p[3] = 0;
        p[0x57] = 0;
        p[0xAB] = 0;
        func_8002C50C();
        a0[0xC] = 0;
        a0[0xD] = 0;
        a0[0] = 7;
        a0[1] = 0;
        a0[2] = 0;
        a0[3] = 0;
        for (i = 0; i < 16; i++) {
            a0[0x26 + i] = 0;
        }
    }
}
