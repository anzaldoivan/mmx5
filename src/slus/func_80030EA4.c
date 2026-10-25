#include "types.h"

extern u16 D_800E931A;
extern u16 D_800E931C;

void func_80030EA4(u8* arg0) {
    u16 dx = D_800E931A;
    u16 dy = D_800E931C;
    u16 x = *(u16*)(arg0 + 0xA);
    u16 y = *(u16*)(arg0 + 0xE);

    *(u16*)(arg0 + 0x8) = 0;
    *(u16*)(arg0 + 0xC) = 0;
    *(u16*)(arg0 + 0xA) = x + dx;
    *(u16*)(arg0 + 0xE) = y + dy;
}
