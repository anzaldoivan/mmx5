#include "types.h"

extern void func_800132F8(s8 arg);
extern u16 D_800C9320;

void func_8001EFF0(u8* p) {
    s16 t;
    s32 flag;

    t = --*(s16*)(p + 4);
    flag = 0;
    if (t < 301) {
        flag = (D_800C9320 & 0x8F0) != 0;
    }
    if (t <= 0) {
        flag = 1;
    }
    if (flag) {
        p[1]++;
        func_800132F8(8);
    }
}
