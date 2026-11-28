#include "types.h"
#include "mmx5/globals.h"

extern u8* func_8002C938();
extern s8 D_8009A0A5;

void func_800EF908_ovl04(u8* arg0) {
    u8* base = g_playthrough_state.u;
    u8* p;
    s32 one;

    if ((s8)base[0x1D] == 2) {
        one = 1;
        p = func_8002C938();
        if (p != 0) {
            p[0] = one;
            p[1] = 0x1E;
            p[2] = one;
        }
        base[0x26] = 0;
        arg0[6] = 6;
    } else if (D_8009A0A5 == 20) {
        one = 1;
        p = func_8002C938();
        if (p != 0) {
            p[0] = one;
            p[1] = 0x1E;
            p[2] = one;
        }
        base[0x26] = 0;
        arg0[6]++;
    } else if (D_8009A0A5 == 2) {
        func_8003D29C(0x14, 0);
    }
}

extern void func_800F0260_ovl04(void);

void func_800EF9D8_ovl04(u8* arg0) {
    u8* q;
    u8* p;

    q = D_8009A1F8.u;
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
    p = g_playthrough_state.u;
    if (p[0x26] & 4) {
        p[0x1D] = 3;
        arg0[6]++;
    }
}

void func_800EFAC8_ovl04(u8* a0) {
    if (D_8009A0AA - D_8009A1F8.h[5] <= (u16)D_8009A1F8.h[0x18]) {
        D_8009A1F8.h[0xE] = 0xB40;
        D_8009A1F8.h[0x12] = 0xB40;
        a0[5] = 3;
        a0[6] = 0;
        func_8003D2C4();
    } else {
        D_8009A1F8.h[5] += 2;
        D_8009A1F8.h[0xE] += 2;
        D_8009A1F8.h[0x12] += 2;
    }
}

extern signed char D_8009A0A5;
extern s8 D_800D1C26;

void func_800EFB50_ovl04(u8* a0) {
    u8* d;

    if (D_8009A0A5 == 2) {
        D_800D1C26 = 1;
        d = D_8009A1F8.u;
        a0[6] = 3;
        d[0x44] = 0;
        *(s32*)(a0 + 0x14) = *(s32*)(d + 0x8);
        *(s32*)(a0 + 0x18) = *(s32*)(d + 0xC);
        *(u16*)(d + 0x26) = *(u16*)(a0 + 0x16);
        *(u16*)(d + 0x24) = *(u16*)(a0 + 0x16);
        *(u16*)(d + 0x1E) = *(u16*)(a0 + 0x16);
        *(u16*)(d + 0x1C) = *(u16*)(a0 + 0x16);
        *(u16*)(d + 0x2A) = *(u16*)(a0 + 0x1A);
        *(u16*)(d + 0x28) = *(u16*)(a0 + 0x1A);
        *(u16*)(d + 0x22) = *(u16*)(a0 + 0x1A);
        *(u16*)(d + 0x20) = *(u16*)(a0 + 0x1A);
    }
}
