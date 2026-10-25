#include "types.h"

extern s8 D_800D1C01;
extern void func_80017214(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F2C1C_ovl20(u8* a0) {
    if (D_800D1C01 == 6) {
        func_80017214(a0, 0, 1);
    } else {
        func_80017214(a0, 0, 0);
    }
    func_8002D9EC(a0, 0x80, 0x80);
}
