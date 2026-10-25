#include "types.h"

extern void func_8002C50C(void);
extern s16 func_8001FF18(void*, s32);
extern u8* func_8002D53C(void);
extern u8* func_8002D27C(void);
extern u8 D_80070F7C[];

void func_800F3260_ovl24(u8* arg0) {
    u8* p;

    arg0[2]++;
    func_8002C50C();
    func_8001FF18(D_80070F7C, 0);
    p = func_8002D53C();
    if (p != 0) {
        p[0] = 1;
        p[1] = 0xE;
        p[2] = 0;
    }
    p = func_8002D27C();
    if (p != 0) {
        p[0] = 1;
        p[1] = 0x3E;
        p[2] = 0;
    }
    arg0[3] = 6;
}
