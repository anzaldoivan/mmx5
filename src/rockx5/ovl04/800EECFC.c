#include "types.h"
#include "mmx5/globals.h"

extern u8* alloc_class3_slot(void);
extern u8 D_8009A1F8[];
extern s8 D_800D1C26;

void func_800EECFC_ovl04(u8* arg0) {
    u8* p;
    u8* q;
    u8* r;

    if (D_800D1C26 != 0) {
        func_8003D2C4();
        p = alloc_class3_slot();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0xE;
            p[2] = 0xC;
            r = g_Player;
            *(s32*)(p + 0x8) = *(s32*)(r + 0x8);
            *(s32*)(p + 0xC) = *(s32*)(r + 0xC);
        }
        q = D_8009A1F8;
        q[0x44] = 0;
        *(s32*)(arg0 + 0x14) = *(s32*)(q + 0x8);
        *(s32*)(arg0 + 0x18) = *(s32*)(q + 0xC);
        *(s16*)(q + 0x26) = *(s16*)(arg0 + 0x16);
        *(s16*)(q + 0x24) = *(s16*)(arg0 + 0x16);
        *(s16*)(q + 0x1E) = *(s16*)(arg0 + 0x16);
        *(s16*)(q + 0x1C) = *(s16*)(arg0 + 0x16);
        *(s16*)(q + 0x2A) = *(s16*)(arg0 + 0x1A);
        *(s16*)(q + 0x28) = *(s16*)(arg0 + 0x1A);
        *(s16*)(q + 0x22) = *(s16*)(arg0 + 0x1A);
        *(s16*)(q + 0x20) = *(s16*)(arg0 + 0x1A);
        arg0[6]++;
    }
}

extern void func_800F0260_ovl04(void);
extern u8 D_8009A1F8[];
extern s8 D_800D1C1D;

void func_800EEE00_ovl04(u8* arg0) {
    s32 flag;
    s16 x;
    s16 y;
    u8* p;
    u8* q;

    flag = 0;
    p = g_Player;
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

extern void func_800F0260_ovl04(void);
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
    p = g_Player;
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
