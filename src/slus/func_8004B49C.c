#include "types.h"
#include "addr.h"

extern u8* func_8002D0E4(void);
extern u8* func_8002CC08(s32 p, s32 backward);
extern void func_80017214(u8* a0, s32 a1, s32 a2);
extern void func_800171E8(u8* obj, s32 state);
extern void func_8003CEAC(s32 arg0, s32 arg1, s32 arg2);
extern u8 D_8009A0A0[];
extern u8 D_80077498[][3];
extern u8 D_8007B3D8[];
extern u8 D_800D1C4A;

void func_8004B49C(u8* obj, u8* g) {
    u8* b;
    u8* p;
    u8* q;
    s32 snd;
    s32 st;
    s32 id;
    u32 fc;
    s32 m;

    obj[3] = 1;
    if (D_80077498[((s8*)obj)[1] - 0x18][2] != 0 && !(((s8*)obj)[0] & 0x80) &&
        (b = D_8009A0A0, *(s32*)(b + 0xFC) & 0x8000)) {
        p = func_8002D0E4();
        if (p != 0) {
            p[0] = 0x21;
            p[1] = 3;
            p[2] = 0x10;
            p[0x14] = g[0x14];
            *(u8**)(p + 0x3C) = D_1F80001C.bytes + D_1F80001C.s32s[11];
            *(u8**)(p + 0x30) = D_8007B3D8;
            *(s16*)(p + 0x40) = 0;
            *(s16*)(p + 0x42) = 0x7802;
            p[0x16] = 0;
            *(s32*)(p + 8) = *(s32*)(g + 8);
            *(s32*)(p + 0xC) = *(s32*)(g + 0xC);
            p[0x15] = g[0x15];
            p[0x5C] = g[0x17];
            p[0x5D] = obj[1];
        }
    }
    if (!(((s8*)obj)[0] & 0x80)) {
        *(s16*)(obj + 0x40) = *(s16*)(g + 0x40);
        *(s32*)(obj + 0x3C) = *(s32*)(g + 0x3C);
        *(s32*)(obj + 0x30) = *(s32*)(g + 0x30);
        *(s16*)(obj + 0x42) = 0x7801;
        obj[0x16] = 2;
    }
    q = D_8009A0A0;
    if (((s8*)q)[0xA6] != 0 && ((s8*)obj)[1] != 0x2C &&
        !(((s8*)obj)[0] & 0x80)) {
        p = func_8002CC08(0, 1);
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x2B;
            p[2] = obj[2];
            p[0x14] = obj[0x14];
            *(s16*)(p + 0x40) = *(s16*)(obj + 0x40);
            *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
            *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
            *(s16*)(p + 0x42) = 0x7843;
            p[0x16] = 2;
            p[0x15] = obj[0x15];
            *(s32*)(p + 0x84) = *(s32*)(obj + 0x84);
            p[0x99] = obj[1];
            p[4] = 0;
        }
    }
    if (((s8*)obj)[0] & 0x80) {
        s32 k = ((s8*)obj)[1];
        snd = D_80077498[k - 0x18][0];
        if (k == 0x1C) {
            u8* h = D_8009A0A0;
            func_80017214(obj, 0x74, h[0x45] & 0x1F);
            obj[0x44] = h[0x44];
        } else {
            func_800171E8(obj, snd);
        }
        if (((s8*)obj)[1] == 0x23) {
            *(s32*)(obj + 0x8C) = 0;
        }
        if ((u32)(obj[1] - 0x26) < 4) {
            *(s16*)(obj + 0x42) = 0x7842;
        } else {
            *(s16*)(obj + 0x42) = 0x7843;
        }
        obj[4]++;
        return;
    } else {
        if (((s8*)obj)[1] == 0x2C) {
            u8* r = *(u8**)(obj + 0x7C);
            *(s16*)(obj + 0x40) = *(s16*)(r + 0x40);
            *(s32*)(obj + 0x3C) = *(s32*)(r + 0x3C);
            *(s32*)(obj + 0x30) = *(s32*)(r + 0x30);
        }
        if ((u32)(obj[1] - 0x26) < 4) {
            *(s16*)(obj + 0x42) = 0x7800;
        }
        id = ((s8*)obj)[1];
        snd = D_80077498[id - 0x18][0];
        st = D_80077498[id - 0x18][1];
        if (st == 3) {
            if (D_800D1C4A & 0x10) {
                st = 0x4E;
                if (*(s32*)(g + 0xFC) & 0x4000) {
                    st = 0x4D;
                }
            } else {
                fc = *(u32*)(g + 0xFC);
                if (fc & 0x10000) {
                    st = 0x4E;
                } else if (fc & 0x4000) {
                    st = 0x4D;
                }
            }
        }
        if (((s8*)obj)[1] == 0x1C) {
            func_80017214(obj, 0x74, g[0x45] & 0x1F);
            obj[0x44] = g[0x44];
        } else {
            func_800171E8(obj, snd);
        }
        if (((s8*)obj)[1] == 0x22) {
            *(s16*)(obj + 0x42) = 0x7802;
        } else {
            func_8003CEAC(st, 1, 1);
        }
        if (((s8*)obj)[1] == 0x23) {
            *(s32*)(obj + 0x8C) = 0;
            *(s32*)(obj + 0x90) = 0;
        }
        if (((s8*)obj)[1] != 0x23) {
            obj[0x64] = obj[0x45];
        } else {
            obj[0x64] = 0;
        }
    }
    obj[4]++;
}
