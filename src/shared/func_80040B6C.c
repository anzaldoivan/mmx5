#include "types.h"

extern void func_8003A94C(void);

s32 func_80040B6C(u8* arg0) {
    u32 flag;
    u8 cnt;

    flag = arg0[0x80];
    cnt = --arg0[0xE8];
    flag >>= 7;
    if (cnt == 0) {
        flag = 1;
    }
    if (flag != 0) {
        func_8003A94C();
        return 1;
    }
    return 0;
}
