#include "types.h"

extern void func_8002D720(u8* arg0);
extern u8 D_8009A0A0[];
extern s8 D_800D1C0F;

void func_800F39BC_ovl05(u8* arg0) {
    u8* p = D_8009A0A0;

    if ((p[0x5C] & 0x7F) && *(s16*)(p + 0xA) >= 0x1134) {
        D_800D1C0F = 0x40;
        func_8002D720(arg0);
    }
}
