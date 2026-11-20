#include "types.h"

extern u8 D_800D1C00[];
void func_80032CEC();

void func_800F2FD0_ovl20(u8* arg0) {
    u8* p = D_800D1C00;
    s32 t = ((s8*)p)[0x27];
    u16 c;

    if (t == 0x20) {
        *(u16*)(arg0 + 0x34) = 0x7FFF;
        func_80032CEC();
    } else {
        c = t;
        *(u16*)(arg0 + 0x34) = c | (c << 5) | (c << 10);
        if (((s8*)p)[0x27] == 0) {
            arg0[3] = 0;
        } else {
            func_80032CEC();
        }
    }
}
