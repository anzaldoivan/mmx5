#include "types.h"

extern void func_8003CE30(void);
extern void func_8003A190(u8*);
extern void func_8003B33C(u8*, s32);

void func_800399D4(u8* a0) {
    s32 f;
    u8 t;

    if (*(s8*)(a0 + 0xD4) > 0 && *(s8*)(a0 + 0xA4) <= 0) {
        func_8003CE30();
        func_8003A190(a0);
        t = a0[0x17];
        f = (t == 5);
        if (t == 6) {
            f = 1;
        }
        if (t == 12) {
            f = 1;
        }
        if (f) {
            func_8003B33C(a0, 0x26);
        }
        a0[0x15] = 0x40;
        *(s8*)(a0 + 0xD4) = -1;
        a0[0x8C] = 0;
        a0[0x5] = 0x13;
        a0[0x6] = 0;
    }
}
