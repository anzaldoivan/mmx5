#include "types.h"

extern u8 D_8009A0A0[];
extern u8 D_8009A1F8[];
extern u8 D_800D1C00[];

void func_800EF584_ovl04(void) {
    u8* a = D_8009A0A0;
    u8* b = D_8009A1F8;
    u8* a2;
    u8* b2;
    u8* a3;
    u8* b3;
    u8* c;
    s16 d;
    u8 t;

    d = *(u16*)(a + 0xE) - *(u16*)(b + 0xE);
    if (d >= 0xDB) {
        *(u16*)(a + 0xE) = *(u16*)(b + 0xE) + 0xDB;
    }
    if (d < -4) {
        if ((a[0x89] & 8) && *(s8*)(a + 5) != 11 && *(s8*)(a + 0xD3) == 0) {
            t = a[0x5C];
            *(s8*)(a + 0x5C) = -0x80;
            c = D_800D1C00;
            *(s32*)(c + 0xB8) += t & 0x7F;
        } else {
            b2 = D_8009A1F8;
            a2 = D_8009A0A0;
            *(u16*)(a2 + 0xE) = *(u16*)(b2 + 0xE) - 4;
        }
    }
    a3 = D_8009A0A0;
    b3 = D_8009A1F8;
    if (*(s16*)(a3 + 0xA) < *(s16*)(b3 + 0xA)) {
        *(s16*)(a3 + 0xA) = *(s16*)(b3 + 0xA);
    }
}
