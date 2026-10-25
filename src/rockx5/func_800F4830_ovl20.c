#include "types.h"

extern u8 D_800D1C00[];
extern void func_80017214(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F4830_ovl20(u8* a0) {
    u8* p = D_800D1C00;
    s32 v = ((s8*)p)[1];
    s32 a2;

    if (v == 8) {
        a2 = 1;
        if (p[0xCB] & 1) {
            a2 = 3;
        }
    } else if (v == 9) {
        a2 = 2;
        if (p[0xCB] & 1) {
            a2 = 4;
        }
    } else {
        a2 = 0;
    }
    func_80017214(a0, 3, a2);
    func_8002D9EC(a0, 0x80, 0x40);
}
