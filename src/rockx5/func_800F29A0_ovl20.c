#include "types.h"

extern u8 D_800D1C00[];
extern void func_80017214(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F29A0_ovl20(u8* a0) {
    s8* p = (s8*)D_800D1C00;
    s32 v = p[0x28];

    if (v < 8 && p[0x2D] == 0) {
        func_80017214(a0, 3, v);
        func_8002D9EC(a0, 0x40, 0x40);
    } else {
        a0[3] = 0;
    }
}
