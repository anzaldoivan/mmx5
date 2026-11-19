#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "addr.h"

extern u8 D_80091C38[];
extern u8* D_800E8514;
extern u8* D_800E8518;
extern u8* D_800E851C;
extern u8* D_800E8520;
extern u8* D_800E8524;
extern u8* D_800E8528;
extern u8* D_800E852C;
extern u8 D_800E8530;
extern u8* D_800E8534;
extern s16 D_800E8538;
extern u16 D_800E8540[];
extern u8 D_800E8580;
extern u8 D_800E8581;
extern u8* D_800715E4[];
extern u16 D_80070474[];
extern u16 D_80071754[];
extern u8 D_800D1C00[];

static inline void func_8002385C_tail(u8* g) {
    if ((s8)D_800D1C00[0xC] == 0xB) {
        *(s16*)(g + 0xA) = 1;
    } else {
        *(s16*)(g + 0xA) = 50;
    }
    g[0xD] = 0;
}

void func_8002385C(s32 a0, s32 a1, s32 a2) {
    u16 id = a0;
    u8 arg1 = a1;
    u8 flag = a2;
    u8* g = D_80091C38;
    u8 st;
    u8* p;
    u16* src;
    u16* dst;
    s32 i;
    s8 k;
    u8 c;
    u8* base;
    u8* q;
    u8** tbl;

    st = g[0xC];
    if (st != 0) {
        if (st == 0x80) {
            *(u16*)(g + 0x10) = id | 0x8000;
            return;
        }
        p = D_800E8518;
        if (p != 0 && ((s8*)p)[1] == 0x16) {
            p[0] = 0;
            D_800E8518[3] = 0;
        }
        p = D_800E851C;
        if (p != 0 && ((s8*)p)[1] == 0x16) {
            p[0] = 0;
            D_800E851C[3] = 0;
        }
        p = D_800E8524;
        if (p != 0 && ((s8*)p)[1] == 0x16) {
            p[0] = 0;
            D_800E8524[3] = 0;
        }
        p = D_800E8520;
        if (p != 0 && ((s8*)p)[1] == 0x16) {
            p[0] = 0;
            D_800E8520[3] = 0;
        }
        p = D_800E852C;
        if (p != 0 && ((s8*)p)[1] == 0x16) {
            p[0] = 0;
            D_800E852C[3] = 0;
        }
        p = D_800E8528;
        if (p != 0 && ((s8*)p)[1] == 0x16) {
            p[0] = 0;
            D_800E8528[3] = 0;
        }
        g[0xC] = 0x80;
        *(s16*)(g + 0xA) = 50;
        g[0xD] = 4;
        *(u16*)(g + 0x10) = id | 0x8000;
        return;
    }
    {
        u8 ff = 0xFF;
        *(s16*)(g + 0x10) = 0;
        D_800E8530 = ff;
    }
    D_800E8514 = 0;
    D_800E8518 = 0;
    D_800E851C = 0;
    D_800E8520 = 0;
    D_800E8524 = 0;
    D_800E8528 = 0;
    D_800E852C = 0;
    g[0xC] = 0x80;
    g[0xE] = 0;
    if (flag) {
        *(s16*)(g + 0xA) = 60;
        g[0xD] = 6;
        return;
    }
    {
        u8 a = D_800D1C00[0x24];
        u8 b = D_800D1C00[0x1F];
        dst = D_800E8540;
        D_800D1C00[0x1F] = 0;
        D_800D1C00[0x24] = 0;
        D_800E8581 = a;
        D_800E8580 = b;
    }
    if ((s8)D_800D1C00[0xC] != 0xD) {
        src = (u16*)(D_1F800028 + 0x2A0);
    } else {
        src = (u16*)(D_1F800028 + 0x7C0);
    }
    for (i = 0; i < 32; i++) {
        *dst++ = *src++;
    }
    src = D_80070474;
    if ((s8)D_800D1C00[0xC] != 0xD) {
        func_8002C338(0x15, src, 2);
    } else {
        func_8002C338(0x3E, src, 2);
    }
    if (!(D_800E8530 & 0x80)) {
        u8** e = &D_800E8534;
        c = D_800E8530;
        tbl = D_800715E4;
        k = D_800D1C00[0x44];
        *e = tbl[k] + c * 6;
        if (k == 0) {
            src = D_80071754;
            dst = (u16*)(D_1F800028 + ((*e)[3] * 128 + 0x360));
            for (i = 0; i < 16; i++) {
                *dst++ = *src++;
            }
        }
    }
    *(u8**)g = D_1F800048 + ((s32*)D_1F800048)[id];
    *(u16*)(g + 4) = **(u16**)g;
    *(s16*)(g + 6) = -0x5C;
    *(s16*)(g + 8) = 0x1D;
    g[0xF] = 1;
    D_800E8538 = 0;
    if ((s8)D_800D1C00[0xC] != 0xB) {
        if ((s8)D_800D1C00[0xC] != 0xF) {
            q = alloc_class6_slot();
            if (q != 0) {
                ((s8*)q)[0] = -0x65;
                q[1] = 2;
                q[2] = 0;
                *(s32*)(q + 0x48) = 0;
                if (!(*(u16*)(g + 4) & 0x800)) {
                    if (D_800E8530 == 0x80) {
                        *(s32*)(q + 0x48) = 0x38;
                    }
                } else if (D_800E8530 == 0xFF) {
                    *(s32*)(q + 0x48) = 0x78;
                } else {
                    *(s32*)(q + 0x48) = 0x70;
                }
            }
        }
        func_8002385C_tail(g);
        return;
    }
    func_8002385C_tail(g);
}
