#include "types.h"

extern s8 D_8009A424;
extern u8* func_8002D27C(void);
extern s32 func_8002C218(void);

void func_800EEE74_ovl23(u8* a0) {
    s32 i;
    u8* p;

    if (D_8009A424 == 0) {
        for (i = 0; i < 2; i++) {
            p = func_8002D27C();
            if (p != 0) {
                p[0] = 0x41;
                p[1] = 0x1C;
                p[2] = i;
            }
        }
        a0[2] = 0;
        a0[1]++;
        func_8002C218();
        *(s16*)(a0 + 4) = 2;
    }
}
