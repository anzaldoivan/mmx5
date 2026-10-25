#include "types.h"

extern signed char D_8009A424;
extern void func_8001E668(void);
extern void func_8002C50C(void);

void func_800F101C_ovl20(u8* a0) {
    s32 i;
    s32 n;
    u8* p;
    u8 b;

    if (D_8009A424 == 0) {
        for (i = 15, p = a0 + 0x35; i >= 0; i--) {
            *p-- = 0;
        }
        func_8001E668();
        func_8002C50C();
        if (a0[0x10F] == 2) {
            a0[0x10F] = 3;
        } else if (a0[0x10F] == 4) {
            a0[0x10F] = 5;
        }
        n = ((s8*)a0)[0xC];
        if (n >= 11) {
            a0[0] = 7;
        } else {
            b = a0[0x4C];
            if (n < 9 && ((b >> (n - 1)) & 1)) {
                a0[0] = 7;
            } else {
                a0[0] = 5;
            }
        }
        a0[1] = 0;
        a0[2] = 0;
        a0[3] = 0;
    }
}
