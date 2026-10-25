#include "types.h"

extern u8* func_8002D27C(void);

void func_800EEE9C_ovl21(u8* a0) {
    s32 i;
    u8* p;

    for (i = 0; i < 4; i++) {
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x30;
            p[2] = i;
            *(u8**)(p + 0x50) = a0;
        }
    }
    *(s16*)(a0 + 4) = 1;
    a0[1]++;
}
