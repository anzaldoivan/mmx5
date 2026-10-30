#include "types.h"

extern void func_80017214(u8* a0, s32 a1, s32 a2);
extern void func_8002D89C(u8*);
extern s8 D_800D1C2A;

void func_800F4260_ovl20(u8* arg0) {
    func_80017214(arg0, 6, D_800D1C2A);
    func_8002D89C(arg0);
}
