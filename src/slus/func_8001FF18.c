#include "types.h"

extern u8* func_8002D27C(void);

u8 func_8001FF18(u8* arg0, s32 arg1) {
    u8* p;
    u8 i;
    u8 kind;

    i = 0;
    kind = arg1;
    if (*arg0 != 0) {
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x20;
            *(u8**)(p + 0x50) = arg0;
            *(s16*)(p + 0xA) = *arg0++;
            p[0x55] = kind;
        }
    } else {
        arg0++;
    }
    while (*arg0 != 0xFF) {
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x1F;
            p[2] = *arg0++;
            p[7] = i++;
            *(s16*)(p + 0xE) = *arg0++;
            *(s16*)(p + 0xA) = *arg0++;
            p[0x55] = kind;
        }
    }
    return arg0[1];
}
