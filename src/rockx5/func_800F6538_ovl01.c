#include "types.h"

extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern int func_8002D7A0();

void func_800F6538_ovl01(u8* a0) {
    s8 state = ((s8*)a0)[5];

    if (state == 0) {
        if (func_8002D938(a0, 0x30, 0x30) == 0) {
            func_8002D9EC(a0, 0x20, 0x20);
        } else {
            a0[5]++;
        }
    } else if (state == 1) {
        func_8002D7A0(a0);
    }
}
