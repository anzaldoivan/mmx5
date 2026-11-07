#include "types.h"

extern void func_80013288(s32);
extern void func_80022D98(void);
extern void func_8003DF20(u8* p);
extern void func_8003EE38(u8* p);
extern void func_8003F250(u8* p);
extern void func_8003F35C(void);
extern u8 D_8009A0A0[];
extern u8 D_800C9310;
extern s8 D_800E9528;

void func_80034E90(u8* arg0) {
    u8* p = D_8009A0A0;

    if (*(s32*)(arg0 + 0x38) == 0) {
        if (*(s8*)(p + 2) == 0) {
            func_8003F35C();
            if (D_800E9528 != *(s8*)(p + 0x93)) {
                func_8003F250(p);
            }
            func_8003EE38(p);
            if (D_800E9528 != *(s8*)(p + 0x93)) {
                if (D_800E9528 == 6) {
                    if (p[0x91] != 0) {
                        p[0x91] = 1;
                    }
                    if (p[0x92] != 0) {
                        p[0x92] = 1;
                    }
                }
                func_8003DF20(p);
            }
        }
        D_800C9310 |= 1;
        func_80022D98();
        func_80013288(8);
    }
    arg0[5] = 3;
}
