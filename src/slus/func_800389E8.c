#include "types.h"

extern void func_8003A2C8(void* arg0);
extern void func_8003EC00(u8* obj);
extern void func_8003C5D8(u8* obj);
extern void func_80038D44(u8* obj);
extern s32 func_8003E6FC(void*, s8);
extern u8 D_800D1C00[];
extern u8 D_8009A11A;
extern u8 D_800C6A10[];
extern u8 D_8009A0FC;
extern s8 D_800D1C1C;

void func_800389E8(u8* obj) {
    u8* p;
    u8* g1;
    u8* g2;
    u8* g3;
    u8* g4;
    u8* g5;
    s32 i;
    s32 v;
    u8 t;
    s8 st;
    s32 c;

    if (*(s8*)(obj + 0xF0) != 0) {
        return;
    }
    st = *(s8*)(obj + 5);
    if (st == 0) {
        return;
    }
    if (st == 1) {
        return;
    }
    c = 0xC;
    if ((obj[0x70] & 0xC) == c) {
        g1 = D_800D1C00;
        *(s32*)(g1 + 0xB8) += obj[0x5C] & 0x7F;
        *(s8*)(obj + 0x5C) = -0x80;
    }
    if ((obj[0x70] & 3) == 3) {
        g2 = D_800D1C00;
        *(s32*)(g2 + 0xB8) += obj[0x5C] & 0x7F;
        *(s8*)(obj + 0x5C) = -0x80;
    }
    if (*(s8*)(obj + 0x5C) != -0x80) {
        t = obj[0x89];
        if ((t & 0xC) == c || (t & 3) == 3) {
            if (*(s8*)(obj + 0x14B) != -1 || *(s8*)(obj + 2) == 0) {
                D_8009A11A = 0;
            }
            obj[0xF8] = 0x4B;
            obj[0x5C] &= 0x7F;
            v = *(s8*)(obj + 0x5C);
            if (*(s8*)(obj + 0xF9) >= v) {
                g3 = D_800D1C00;
                *(s32*)(g3 + 0xB8) += v;
            }
            p = D_800C6A10;
            obj[0x5C] -= obj[0xF9];
            for (i = 0; i < 0x40; i++) {
                p[0x76] = 0;
                p[0x72] = 0;
                p += 0xA4;
            }
            if (*(s8*)(obj + 0x5C) > 0) {
                obj[0x5C] |= 0x80;
                obj[0xCA] = 0;
                obj[0x63] = 1;
                obj[0xA5] = obj[0x15];
                g4 = D_800D1C00;
                *(s32*)(g4 + 0xB8) += *(s8*)(obj + 0xF9);
            } else {
                *(s8*)(obj + 0x5C) = -0x80;
            }
        }
    }
    if (*(s8*)(obj + 0x79) != 0 && *(s8*)(obj + 0x61) == 0 &&
        *(s8*)(obj + 0x7A) != 1) {
        g5 = D_800D1C00;
        *(s32*)(g5 + 0xB8) += D_8009A0FC & 0x7F;
        *(s8*)(obj + 0x5C) = -0x80;
    }
    if (*(s8*)(obj + 0x5C) == -0x80) {
        obj[0x5C] = 0;
        D_800D1C1C = 1;
        func_8003A2C8(obj);
        func_8003EC00(obj);
        *(s32*)(obj + 0x68) = 0;
        *(s32*)(obj + 0x54) = 0;
        obj[4] = 2;
        obj[5] = 0;
        obj[6] = 0;
        obj[0xFB] = 0;
        obj[0x14B] = 0;
        obj[0x154] = 0;
        if (*(s8*)(obj + 2) != 0) {
            obj[0x7A] = 0;
        }
        func_8003C5D8(obj);
        return;
    }
    if (*(s8*)(obj + 0x61) != 0) {
        obj[0x61]--;
        if (*(s8*)(obj + 0x61) == 0) {
            obj[0xA4] = 0;
            func_8003C5D8(obj);
        }
    }
    if (*(s8*)(obj + 0x5C) > 0) {
        return;
    }
    func_80038D44(obj);
    if (*(s8*)(obj + 2) == 0) {
        s32 lim = *(s16*)(obj + 0x148);
        s32 step = lim / 8;
        s32 w;
        *(s16*)(obj + 0xA8) += step;
        w = *(s16*)(obj + 0xA8);
        if (lim < w || lim - w < step) {
            *(s16*)(obj + 0xA8) = *(s16*)(obj + 0x148);
        }
    } else {
        *(s16*)(obj + 0xAC) += func_8003E6FC(obj, 2) / 2;
        if (*(s16*)(obj + 0xAC) >= *(s16*)(obj + 0x148)) {
            *(s16*)(obj + 0xAC) = *(s16*)(obj + 0x148);
        }
    }
}
