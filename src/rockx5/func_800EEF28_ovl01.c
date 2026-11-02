#include "types.h"

extern u16 D_80093E68;
extern u8 D_8009A0A0[];
extern u8 D_8009A1F8[];
extern u16 D_8009A42E;
extern u8 D_800C9310;
extern u16 D_800D50DE;

void func_800EEF28_ovl01(u8* arg0) {
    u8* s;
    u8* g;
    u8* q;
    s32 t;

    s = D_8009A1F8;
    if (*(s16*)(s + 0xA) < 0x1D31) {
        *(s32*)(s + 8) += *(s32*)(arg0 + 0x14);
        *(u16*)(s + 0x26) = *(u16*)(s + 0xA);
        *(u16*)(s + 0x1E) = *(u16*)(s + 0xA);
        g = D_8009A0A0;
        *(s32*)(g + 8) += *(s32*)(arg0 + 0x14);
    }
    q = arg0 + 0x14;
    t = arg0[0x1A] - 1;
    q[6] = t;
    if ((t & 0xFF) == 0) {
        t = arg0[0x19] - 1;
        q[5] = t;
        if ((t & 3) == 0) {
            D_800C9310 |= 1;
            arg0[0x19] = 4;
            D_800D50DE = 0;
            D_8009A42E = 0;
            D_80093E68 = 0;
            arg0[0x1A] = 2;
            arg0[0x1B]++;
        } else {
            D_800D50DE = 0x1F;
            D_8009A42E = 0x3E0;
            D_80093E68 = 0x7C00;
            arg0[0x1A] = 1;
        }
        if (arg0[0x1B] >= 3) {
            arg0[0x19] = 0;
            arg0[5]++;
        }
    }
}
