#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

extern s16 D_8007183C[][3];
extern u8* D_8009E794;

void func_80026080(s32 arg0, u8 arg1) {
    u8 code;
    u8* base;
    u8* h;
    u8* e;
    u8* p;
    u8* q;
    u8* g;
    s32 n;
    u16 z;
    u16 r;
    s16 x;
    s16 y;
    u8 b0;
    u16 d;
    u16 v;
    u32 t;

    if (arg0 == 0x10) {
        base = D_1F80001C.bytes + *(s32*)(D_1F80001C.bytes + 0x5C);
    } else {
        base = D_1F80001C.bytes + *(s32*)(D_1F80001C.bytes + 4);
    }
    h = base + arg1 * 4;
    n = *(u16*)h;
    p = ((u8**)&D_1F800100)[2];
    q = ((u8**)&D_1F800100)[3];
    e = base + *(u16*)(h + 2) * 4;
    z = D_8007183C[arg0][2];
    if (n != 0) {
        do {
            x = D_8007183C[arg0][0] + (s8)e[2];
            y = D_8007183C[arg0][1] + (s8)e[3];
            b0 = e[0];
            if (arg0 == 14 || arg0 == 15) {
                y += ((g_playthrough_state.s[0xA2] - 0x20) >> 1) * 2;
            }
            d = (b0 & 3) << 8;
            code = 0x7D;
            d = e[1] | d;
            p[7] = code;
            *(s16*)(p + 8) = x;
            *(s16*)(p + 0xA) = y;
            *(s16*)(p + 0xE) = z + ((b0 & 0xC) >> 2);
            p[3] = 3;
            e += 4;
            n--;
            r = d / 80;
            v = (r << 8) + d % 80 + 0x5B0;
            p[0xC] = v << 4;
            p[0xD] = v & 0xF0;
            q[3] = 1;
            *(u32*)(q + 4) = (v >> 8) | 0xE1000000;
            t = (u32)p & 0xFFFFFF;
            *(u32*)q =
                (*(u32*)q & 0xFF000000) |
                (t &
                 0xFFFFFF); // !FAKE: redundant second mask keeps the addPrim insert order (C0290)
            t = (u32)(q + 8) & 0xFFFFFF;
            *(u32*)p = (*(u32*)p & 0xFF000000) | t;
            q += 8;
            p += 0x10;
        } while (n != 0);
    }
    g = D_8009E794;
    *(u32*)(p - 0x10) =
        (*(u32*)(p - 0x10) & 0xFF000000) | (*(u32*)(g + 0x7C) & 0xFFFFFF);
    *(u32*)(g + 0x7C) = (*(u32*)(g + 0x7C) & 0xFF000000) |
                        ((u32)((u8**)&D_1F800100)[3] & 0xFFFFFF);
    ((u8**)&D_1F800100)[2] = p;
    ((u8**)&D_1F800100)[3] = q;
}
