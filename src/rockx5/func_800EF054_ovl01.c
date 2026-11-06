#include "types.h"

extern u16 D_80093E68;
extern u8 D_8009A0A0[];
extern u8 D_8009A1F8[];
extern u16 D_8009A42E;
extern u16 D_800D50DE;
extern s32 D_800E92F8;

void func_800EF054_ovl01(u8* arg0) {
    u8* s;
    u8* g;
    s32 t;

    s = D_8009A1F8;
    if (*(s16*)(s + 0xA) < 0x1D31) {
        *(s32*)(s + 8) += *(s32*)(arg0 + 0x14);
        *(u16*)(s + 0x26) = *(u16*)(s + 0xA);
        *(u16*)(s + 0x1E) = *(u16*)(s + 0xA);
        g = D_8009A0A0;
        *(s32*)(g + 8) += *(s32*)(arg0 + 0x14);
    }
    arg0[0x19]++;
    if ((u8)(arg0[0x19] % 5) == 0) {
        t = D_800D50DE + 2;
        D_800D50DE = t;
        D_8009A42E += 0x40;
        D_80093E68 += 0x800;
        if ((u16)t >= 0x1F) {
            D_800E92F8 = 1;
            arg0[0x19] = 0x14;
            arg0[5]++;
            *(u16*)(s + 0x26) = 0x2000;
            *(u16*)(s + 0x1E) = 0x2000;
            s[0x4C] = 1;
        }
    }
}
