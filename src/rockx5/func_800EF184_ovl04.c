#include "types.h"

extern void func_800EF584_ovl04(void);
extern u8 D_8009A0A0[];
extern u8 D_8009A1F8[];
extern u8 D_800D1C00[];

void func_800EF184_ovl04(u8* arg0) {
    s32 flag;
    s16 v;
    s16 w;
    u8* p;
    u8* q;
    u8* r;
    u8* o;

    func_800EF584_ovl04();
    p = D_8009A0A0;
    flag = 0;
    if (*(s8*)(p + 0xF3) == 0 || (u32)(p[0xFA] - 2) >= 2) {
        flag = 1;
    }
    if (flag != 0) {
        o = D_8009A1F8;
        *(s32*)(o + 0xC) += 0x4000;
    }
    q = D_8009A1F8;
    v = *(s16*)(q + 0xE);
    if (v >= 0x3C0) {
        *(s16*)(q + 0x2A) = v;
        *(s16*)(q + 0x28) = v;
        *(s16*)(q + 0x22) = v;
        *(s16*)(q + 0x20) = v;
        r = D_800D1C00;
        w = *(s16*)(q + 0xA);
        r[0x26] |= 2;
        *(s16*)(q + 0x26) = w;
        *(s16*)(q + 0x24) = w;
        *(s16*)(q + 0x1E) = w;
        *(s16*)(q + 0x1C) = w;
        arg0[6]++;
    }
}
