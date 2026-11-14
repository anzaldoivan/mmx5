#include "types.h"
#include "addr.h"

extern s32 func_80017214(u8* a0, s32 a1, s32 a2);
extern u8* func_8002D27C(void);
extern u32* D_80098118;
extern u8 D_800F5A14_ovl20[];
extern u16 D_800F5A28_ovl20[][2];
extern u16 D_800F5A68_ovl20[][2];
extern u16 D_800F5A78_ovl20[][2];
extern u16 D_800F5A88_ovl20[][2];
extern u8 D_800D1CCB;

extern View800F4990 D_800D1C00;
extern s8 D_800D1C32;

void func_800F4990_ovl20(u8* obj) {
    u8 t;
    s32 c;
    s32 b;
    u32* g;
    s32 i;
    s32 n;
    s32 k;
    View800F4990* p;
    u8* q;

    g = D_80098118;
    *(s16*)(obj + 0x42) = 0x7800;
    *(s16*)(obj + 0x40) = g[0] >> 7;
    *(s32*)(obj + 0x3C) = (s32)D_1F800020.s32s + D_1F800020.s32s[0];
    *(u8**)(obj + 0x30) = D_800F5A14_ovl20;
    t = obj[2];
    if ((u8)(t - 8) >= 0x18) {
        *(s16*)(obj + 0x42) = 0x78C8;
        obj[0x16] = 3;
        b = (s8)t;
        if (b < 8) {
            *(u16*)(obj + 0xA) = D_800F5A28_ovl20[b][0];
            *(u16*)(obj + 0xE) = D_800F5A28_ovl20[b][1];
        } else {
            *(u16*)(obj + 0xA) = D_800F5A28_ovl20[b - 0x18][0];
            *(u16*)(obj + 0xE) = D_800F5A28_ovl20[b - 0x18][1];
            obj[2] = t - 0x20;
        }
        func_80017214(obj, 0, ((s8*)obj)[2]);
        obj[4] = 1;
    } else {
        c = (s8)t;
        if (c < 12) {
            obj[0x16] = 3;
            *(u16*)(obj + 0xA) = D_800F5A68_ovl20[c - 8][0];
            *(u16*)(obj + 0xE) = D_800F5A68_ovl20[c - 8][1];
            n = c - 8;
            if (D_800D1CCB & 1) {
                n = c - 4;
            }
            func_80017214(obj, 1, n);
            obj[4] = 2;
        } else if (c < 16) {
            obj[0x16] = 3;
            *(u16*)(obj + 0xA) = D_800F5A78_ovl20[c - 12][0];
            *(u16*)(obj + 0xE) = D_800F5A78_ovl20[c - 12][1];
            i = c - 12;
            p = &D_800D1C00;
            if (p->cb & 1) {
                n = p->c6[i];
            } else {
                n = p->c2[i];
            }
            if (n >= 6) {
                n = 5;
            }
            func_80017214(obj, 2, n);
            obj[4] = 3;
        } else if (c == 16) {
            if (D_800D1CCB & 1) {
                func_80017214(obj, 3, 1);
            } else {
                func_80017214(obj, 3, 0);
            }
            obj[0x16] = 3;
            *(s16*)(obj + 0xA) = 0x46A;
            *(s16*)(obj + 0xE) = 0x98;
            obj[4] = 4;
            for (k = 0; k < 2; k++) {
                q = func_8002D27C();
                if (q != 0) {
                    q[0] = 0x41;
                    q[1] = 0x2E;
                    q[2] = k + 0x11;
                }
            }
        } else if (c < 19) {
            obj[0x16] = 3;
            *(u16*)(obj + 0xA) = D_800F5A88_ovl20[c - 17][0];
            *(u16*)(obj + 0xE) = D_800F5A88_ovl20[c - 17][1];
            n = D_800D1C32;
            if (c == 17) {
                func_80017214(obj, 4, n / 10);
            } else {
                func_80017214(obj, 4, n % 10);
            }
            obj[4] = 4;
        }
    }
    obj[0x14] = 1;
    obj[0x15] = 0;
}
