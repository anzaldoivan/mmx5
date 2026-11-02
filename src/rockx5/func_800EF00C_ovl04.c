#include "types.h"

extern void func_8002A080(u8* arg0, s32 arg1, u16 arg2);
extern void func_800F0260_ovl04(void);
extern u8 D_8009A0A0[];
extern u8 D_8009A1F8[];
extern u8 D_800D1C00[];

void func_800EF00C_ovl04(u8* arg0) {
    s32 flag;
    s32 t;
    u16 v;
    s16 x;
    s16 y;
    u8* p;
    u8* q;

    flag = 0;
    p = D_8009A0A0;
    if (*(s8*)(p + 0xF3) == 0 || (u32)(p[0xFA] - 2) >= 2) {
        flag = 1;
    }
    if (flag != 0) {
        *(s32*)(arg0 + 0x14) += 0x4000;
    }
    q = D_8009A1F8;
    t = *(s32*)(q + 0x8);
    *(s16*)(q + 0x26) = *(s16*)(arg0 + 0x16);
    v = *(u16*)(arg0 + 0x16);
    *(PairFB4BC*)(q + 0x14) = *(PairFB4BC*)(q + 0x8);
    *(s16*)(q + 0x24) = v;
    if (*(s16*)(q + 0x1C) < *(s16*)(q + 0xA)) {
        *(s16*)(q + 0xA) = *(s16*)(q + 0x1C);
    }
    if (*(s16*)(q + 0x1E) >= *(s16*)(q + 0xA)) {
        *(s16*)(q + 0xA) = *(s16*)(q + 0x1E);
    }
    if (*(s16*)(q + 0x20) < *(s16*)(q + 0xE)) {
        *(s16*)(q + 0xE) = *(s16*)(q + 0x20);
    }
    if (*(s16*)(q + 0x22) >= *(s16*)(q + 0xE)) {
        *(s16*)(q + 0xE) = *(s16*)(q + 0x22);
    }
    func_8002A080(q, t, v);
    if (*(s16*)(arg0 + 0x16) >= 0xAA0) {
        arg0[6]++;
        D_800D1C00[0x26] |= 2;
        x = *(s16*)(arg0 + 0x16);
        y = *(s16*)(arg0 + 0x1A);
        *(s16*)(q + 0x26) = x;
        *(s16*)(q + 0x24) = x;
        *(s16*)(q + 0x2A) = y;
        *(s16*)(q + 0x28) = y;
        *(s16*)(q + 0xA) = x;
        *(s16*)(q + 0xE) = y;
    }
    func_800F0260_ovl04();
}
