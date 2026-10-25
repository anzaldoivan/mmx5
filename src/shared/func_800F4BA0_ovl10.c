/* Shared body (DK-5), from the banked draft of func_800F4BA0_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8003D29C(s32, s32);
extern void func_800171E8(u8* obj, s32 state);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_8009A0A0[];

void DEDUP_NAME(u8* a0) {
    D_8009A0A0[0xCA] = 0;
    func_8003D29C(0x14, D_8009A0A0[0x15]);
    a0[5] = 1;
    *(u16*)(a0 + 0x42) &= 0x7FFF;
    func_800171E8(a0, 0x14);
    *(s16*)(a0 + 0x7C) = 0x7F;
    *(s16*)(a0 + 0x7E) = 0x19;
    a0[0x61] = 0x19;
    if (*(signed char*)(a0 + 2) == 0) {
        func_8002D9EC(a0, 0x60, 0x60);
    } else {
        a0[3] = 0;
    }
}
