#include "types.h"

extern u8 D_8009A420[];

extern void func_8002002C(s32);

void func_80021A1C(u8* arg0) {
    u8* p = D_8009A420;

    if (((signed char*)p)[4] == 0) {
        if (p[7] == 0) {
            arg0[0] = 0x12;
            arg0[1] = 0;
            arg0[2] = 0;
            arg0[3] = 0;
        } else {
            arg0[0] = 0xC;
            arg0[1] = 5;
            arg0[2] = 2;
            func_8002002C(1);
        }
    }
}
