/* Shared body (DK-5), from the banked draft of func_800F83D0_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_8009A0A0[];
extern u16 D_8009A42E;
extern u8 D_800C9310;
extern u16 D_800D50DE;
extern u16 D_80093E68;

extern void func_800171E8(u8* obj, s32 state);
extern void func_8002C218(void);
extern void func_8003D29C(s32, s32);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void DEDUP_NAME(u8* p) {
    u8* g = D_8009A0A0;

    if (((signed char*)g)[0xCA] != 0) {
        g[0xCA] = 0;
    }
    func_800171E8(p, 0xC);
    func_8002C218();
    D_8009A42E = 0;
    D_800C9310 |= 1;
    D_800D50DE = 0;
    D_80093E68 = 0;
    *(s16*)(p + 0x7C) = 0x7F;
    *(s16*)(p + 0x7E) = 0x19;
    p[0x61] = 0x19;
    *(u16*)(p + 0x42) &= 0x7FFF;
    p[0x5]++;
    func_8003D29C(0x14, g[0x15]);
    func_8002D9EC(p, 0xFF, 0xFF);
}
