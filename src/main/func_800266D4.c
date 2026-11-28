#include "types.h"
#include "addr.h"

extern u16 func_80026570(u16 c);
extern u16 D_800718B0[][4];
extern u8* D_8009E794;

#define C5TO8(x) (((x) << 3) + ((x) >> 2))

void func_800266D4(s16 x0, s16 x1, s16 y0, s16 y1, s32 idx, u32 total,
                   s32 cur) {
    u8* p;
    u16 c;
    u8 r;
    u8 g;
    u8 bl;
    u8* ot;

    p = (&D_1F800108)[2];
    p[3] = 8;
    p[7] = 0x38;
    *(s16*)(p + 0x8) = *(s16*)(p + 0x18) = x0;
    *(s16*)(p + 0x10) = *(s16*)(p + 0x20) = x1;
    *(s16*)(p + 0xA) = *(s16*)(p + 0x12) = y0;
    *(s16*)(p + 0x1A) = *(s16*)(p + 0x22) = y1;
    c = func_80026570(D_800718B0[idx][0]);
    r = c & 0x1F;
    g = (c >> 5) & 0x1F;
    bl = c >> 10;
    p[0x4] = C5TO8(r);
    p[0x5] = C5TO8(g);
    p[0x6] = C5TO8(bl);
    c = func_80026570(D_800718B0[idx][1]);
    r = c & 0x1F;
    g = (c >> 5) & 0x1F;
    bl = c >> 10;
    p[0xC] = C5TO8(r);
    p[0xD] = C5TO8(g);
    p[0xE] = C5TO8(bl);
    c = func_80026570(D_800718B0[idx][2]);
    r = c & 0x1F;
    g = (c >> 5) & 0x1F;
    bl = c >> 10;
    p[0x14] = C5TO8(r);
    p[0x15] = C5TO8(g);
    p[0x16] = C5TO8(bl);
    c = func_80026570(D_800718B0[idx][3]);
    r = c & 0x1F;
    g = (c >> 5) & 0x1F;
    bl = c >> 10;
    p[0x1C] = C5TO8(r);
    p[0x1D] = C5TO8(g);
    p[0x1E] = C5TO8(bl);
    {
        u8 a;
        u8 b;
        s32 v;

        a = p[0x4];
        b = p[0x14];
        if (a == b || total == cur) {
            v = a;
        } else if (cur == 0) {
            v = b;
        } else if (b < a) {
            v = b + (a - b) * cur / total;
        } else {
            v = a + (b - a) * (total - cur) / total;
        }
        p[0x4] = v;
    }
    {
        u8 a;
        u8 b;
        s32 v;

        a = p[0x5];
        b = p[0x15];
        if (a == b || total == cur) {
            v = a;
        } else if (cur == 0) {
            v = b;
        } else if (b < a) {
            v = b + (a - b) * cur / total;
        } else {
            v = a + (b - a) * (total - cur) / total;
        }
        p[0x5] = v;
    }
    {
        u8 a;
        u8 b;
        s32 v;

        a = p[0x6];
        b = p[0x16];
        if (a == b || total == cur) {
            v = a;
        } else if (cur == 0) {
            v = b;
        } else if (b < a) {
            v = b + (a - b) * cur / total;
        } else {
            v = a + (b - a) * (total - cur) / total;
        }
        p[0x6] = v;
    }
    {
        u8 a;
        u8 b;
        s32 v;

        a = p[0xC];
        b = p[0x1C];
        if (a == b || total == cur) {
            v = a;
        } else if (cur == 0) {
            v = b;
        } else if (b < a) {
            v = b + (a - b) * cur / total;
        } else {
            v = a + (b - a) * (total - cur) / total;
        }
        p[0xC] = v;
    }
    {
        u8 a;
        u8 b;
        s32 v;

        a = p[0xD];
        b = p[0x1D];
        if (a == b || total == cur) {
            v = a;
        } else if (cur == 0) {
            v = b;
        } else if (b < a) {
            v = b + (a - b) * cur / total;
        } else {
            v = a + (b - a) * (total - cur) / total;
        }
        p[0xD] = v;
    }
    {
        u8 a;
        u8 b;
        s32 v;

        a = p[0xE];
        b = p[0x1E];
        if (a == b || total == cur) {
            v = a;
        } else if (cur == 0) {
            v = b;
        } else if (b < a) {
            v = b + (a - b) * cur / total;
        } else {
            v = a + (b - a) * (total - cur) / total;
        }
        p[0xE] = v;
    }
    ot = D_8009E794;
    *(u32*)p = (*(u32*)p & 0xFF000000) | (*(u32*)(ot + 0x7C) & 0xFFFFFF);
    *(u32*)(ot + 0x7C) =
        (*(u32*)(ot + 0x7C) & 0xFF000000) | ((u32)p & 0xFFFFFF);
    (&D_1F800108)[2] += 0x24;
}
