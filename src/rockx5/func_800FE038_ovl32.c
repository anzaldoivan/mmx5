#include "types.h"

extern u16 D_800D50DE;
extern u16 D_8009A42E;
extern u16 D_80093E68;

void func_800FE038_ovl32(u8* arg0) {
    u16 r = D_800D50DE + 0x11;
    u16 g = D_8009A42E + 0x2A0;
    u16 b = D_80093E68 + 0x6000;
    if (r > 0x1F) {
        r = 0x1F;
    }
    if (g > 0x3E0) {
        g = 0x3E0;
    }
    if (b > 0x7C00) {
        b = 0x7C00;
    }
    *(u16*)(arg0 + 0x34) = b | (r | g);
}
