#include "types.h"

extern u8 D_8009A0A0[];
extern u8 D_8009A1F8[];
extern void func_8003D29C(s32, s32);

void func_800EFC34_ovl04(u8* arg0) {
    u8* p = D_8009A0A0;

    if ((s8)p[5] == 0x14) {
        u8* q = D_8009A1F8;
        u16 v = *(u16*)(q + 0xA);
        *(s16*)(q + 0x26) = v;
        *(s16*)(q + 0x1E) = v;
        arg0[6]++;
    } else if (*(s16*)(p + 0xA) >= 0xBD0) {
        func_8003D29C(0x14, 0x40);
    }
}
