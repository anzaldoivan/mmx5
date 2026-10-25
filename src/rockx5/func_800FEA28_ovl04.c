#include "types.h"

extern s32 func_80031DD0(u8* a0);
extern s32 func_800317B8(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_800D1C00[];

void func_800FEA28_ovl04(u8* a0) {
    u8* child = *(u8**)(a0 + 0x80);
    u8* g;

    if (func_80031DD0(a0) != 0) {
        g = D_800D1C00;
        g[0x27] |= 1;
    }
    *(u16*)(a0 + 0x42) &= 0x7FFF;
    func_800317B8(a0);
    func_8002D9EC(a0, 0x40, 0x20);
    if (*(s8*)(child + 5) >= 4) {
        a0[5]++;
    }
}
