#include "types.h"

extern void func_80024548(s32);
extern u8 D_8009A1F8[];
extern u8 D_800D1C00[];

void func_800F46A0_ovl06(u8* a0) {
    u8* d = D_8009A1F8;
    u8* g = D_800D1C00;

    a0[0x8B] = 1;
    *(s16*)(a0 + 0x80) = *(s16*)(d + 0x24);
    *(s16*)(a0 + 0x82) = *(s16*)(d + 0x26);
    *(s16*)(d + 0x24) = 0xB50;
    *(s16*)(d + 0x26) = 0xB50;
    *(s16*)(d + 0x28) = 0xE0;
    *(s16*)(d + 0x2A) = 0xE0;
    g[0x24] = 1;
    g[0xA2] = 0x30;
    func_80024548(0);
    g[0x25] = 0;
    *(u8**)(g + 0x20) = a0;
    *(s16*)(a0 + 0x7E) = 3;
    a0[6]++;
}
