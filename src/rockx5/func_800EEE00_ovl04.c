#include "types.h"

extern void func_8002A080(u8* arg0);
extern void func_800F0260_ovl04(void);
extern u8 D_8009A0A0[];
extern u8 D_8009A1F8[];
extern s8 D_800D1C1D;

void func_800EEE00_ovl04(u8* arg0) {
    s32 flag;
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
        *(s32*)(arg0 + 0x14) += 0x8000;
    }
    x = *(s16*)(arg0 + 0x16);
    if (x < 0x521) {
        y = (((x - 0x230) * 0xB0) / 752) + 0xF0;
    } else {
        if (x < 0x550) {
            y = 0x1A0;
        } else {
            y = 0x1A0 - (((x - 0x550) * 0xB0) / 624);
        }
    }
    *(s16*)(arg0 + 0x1A) = y;
    if (x >= 0x7C0) {
        *(s16*)(arg0 + 0x1A) = 0xF0;
        *(s16*)(arg0 + 0x14) = 0;
        arg0[6]++;
        D_800D1C1D = 2;
    }
    q = D_8009A1F8;
    *(s16*)(q + 0x26) = *(s16*)(arg0 + 0x16);
    *(s16*)(q + 0x24) = *(s16*)(arg0 + 0x16);
    *(s16*)(q + 0x2A) = *(s16*)(arg0 + 0x1A);
    *(s16*)(q + 0x28) = *(s16*)(arg0 + 0x1A);
    *(s32*)(q + 0x14) = *(s32*)(q + 0x8);
    *(s32*)(q + 0x18) = *(s32*)(q + 0xC);
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
    func_8002A080(q);
    func_800F0260_ovl04();
}
