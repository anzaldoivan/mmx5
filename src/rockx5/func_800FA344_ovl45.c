#include "types.h"

extern u8* func_8002D53C(void);
extern void func_8002C1C8(void);
extern u8 D_80091C44;
extern u8 D_8009A1F8[];

void func_800FA344_ovl45(u8* arg0) {
    u8* p;
    u8* b;

    if (D_80091C44 == 0) {
        p = func_8002D53C();
        if (p != 0) {
            p[0] = 1;
            p[1] = 10;
            p[0x36] = 50;
            p[2] = 0;
        }
        b = D_8009A1F8;
        *(s16*)(b + 0xB2) = 0;
        *(s16*)(b + 0xB6) = 0x100;
        b[0xF4] = 1;
        func_8002C1C8();
        p = func_8002D53C();
        if (p != 0) {
            p[0] = 1;
            p[1] = 9;
            p[0x36] = 0x11;
            *(s16*)(p + 0x34) = 0x7FFF;
            p[2] = 0;
            *(s32*)(p + 0x38) = 30;
        }
        *(s16*)(arg0 + 4) = 1;
        arg0[1]++;
    }
}
