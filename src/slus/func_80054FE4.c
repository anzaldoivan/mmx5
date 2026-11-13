#include "types.h"
#include "addr.h"

extern int func_8002D760();
extern s32 func_8002B5B4(s32);
extern void func_800171E8(u8* obj, s32 state);
extern void func_8002FB58(u8* obj);
extern u8* func_8002D210();
extern void func_800556B0(u8* obj, s32 a, s32 b);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_8009A0A0[];
extern u8 D_800D1C4A;
extern u8 D_800D1C00[];
extern u8 D_8007C370[];
extern u8 D_800767E0[];
extern u8 D_8007C360[];
extern u8 D_8007C368[];
extern u8 D_8007C708[];
extern u32* D_80098118;
extern s8 D_8007C378[];

void func_80054FE4(u8* obj) {
    s32 hit;
    s32 r;
    s32* base;
    u32* tbl;
    s32 i4;
    s32* q;
    u8* p;
    u8* g;
    u8* g2;
    u8* g3;
    s8 t;
    s8 t2;

    hit = 0;
    g = D_8009A0A0;
    t = ((s8*)obj)[2];
    if (t == 8) {
        if (((s8*)g)[2] == 0) {
            hit = D_800D1C00[0x4B] != 0;
            if (D_800D1C00[0x4A] & 8) {
                hit = 1;
            }
            if (g[0xFA] != 0) {
                hit = 1;
            }
        } else {
            if (D_800D1C4A & 0x10) {
                hit = 1;
            }
        }
    } else {
        if ((D_800D1C00[0x4A] & 2) && (D_8007C370[t] & 0xF)) {
            hit = 1;
        }
        if ((D_800D1C00[0x4A] & 4) && (D_8007C370[(s8)obj[2]] & 0xF0)) {
            hit = 1;
        }
        if (D_800D1C00[0xA1] & D_8007C370[(s8)obj[2]]) {
            hit = 1;
        }
    }
    if (hit) {
        func_8002D760(obj);
        return;
    }
    obj[0xA2] = 1;
    obj[3] = 1;
    *(u8**)(obj + 0x58) = D_800767E0;
    g2 = D_8009A0A0;
    obj[0x14] = g2[0x14];
    *(u8**)(obj + 0x68) = D_8007C360;
    *(u8**)(obj + 0x54) = D_8007C368;
    *(u8**)(obj + 0x30) = D_8007C708;
    r = func_8002B5B4(0x86);
    i4 = r * 4;
    base = D_1F800020.s32s;
    q = (s32*)(r * 4 + (s32)base);
    tbl = D_80098118;
    *(s32*)(obj + 0x3C) = (s32)base + *q;
    *(s16*)(obj + 0x40) = tbl[r] >> 7;
    *(s16*)(obj + 0x42) = ((i4 + 0x18) % 16) | (((r + 6) / 4 + 0x1E0) << 6);
    obj[0x16] = 4;
    obj[0x15] = 0;
    obj[0x75] = 1;
    g2[0xF5] = 0;
    func_800171E8(obj, 0);
    func_8002FB58(obj);
    while ((obj[0x70] & 8) == 0) {
        *(s16*)(obj + 0xE) += 0x10;
        func_8002FB58(obj);
    }
    p = func_8002D210();
    if (p != 0) {
        p[0] = 1;
        p[1] = 0x1A;
        p[2] = 0x10;
        p[0x14] = obj[0x14];
        *(u8**)(p + 0x7C) = obj;
    }
    t2 = ((s8*)obj)[2];
    if (t2 == 8) {
        g3 = D_8009A0A0;
        if (((s8*)g3)[2] == 0) {
            func_800556B0(obj, 0x23, 0x10);
        } else {
            func_800556B0(obj, 0x23, 0x11);
        }
    } else {
        func_800556B0(obj, 0x23, D_8007C378[t2]);
    }
    obj[5] = 0;
    obj[4]++;
    func_8002D9EC(obj, 0x88, 0x88);
}
