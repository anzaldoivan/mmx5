#include "types.h"

extern u8 D_800D1C00[];
extern void func_80017214(u8* a0, s32 a1, s32 a2);
extern void func_8002D89C(u8*);

void func_800F3EA0_ovl20(u8* a0) {
    s8* p = (s8*)D_800D1C00;
    s8 mode = p[0x30];

    if (mode == 4) {
        func_80017214(a0, 5, p[0x31]);
    } else if (mode == 2) {
        func_80017214(a0, 5, p[0x31] + 5);
    } else {
        func_80017214(a0, 5, 8);
    }
    func_8002D89C(a0);
}
