#include "types.h"

extern u8 D_8009A420[];

void func_8001E6AC(void);
void func_80012EAC(void);
void func_8002002C(s32);

void func_800F0A64_ovl24(u8* arg0) {
    u8* p = D_8009A420;

    if (((signed char*)p)[4] == 0) {
        if (p[7] == 0) {
            func_8001E6AC();
            func_80012EAC();
        } else {
            arg0[1] = 5;
            arg0[2] = 2;
            func_8002002C(1);
        }
    }
}
