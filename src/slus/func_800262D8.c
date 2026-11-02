#include "types.h"

void func_800266D4(s16, s16, s16, s16, s32, s32, s32);
extern s16 D_800718A8[][2];
extern s8 D_8009A0A2;
extern s32 D_8009A420;
extern D1C00 D_800D1C00;
extern s8 D_800D1CA2;

void func_800262D8(u8* arg0, s32 arg1) {
    s32 w;
    s32 t;
    s32 k;
    s16 b;
    s16 a;
    s32 v;
    s32 lo;

    v = arg0[0x5C] & 0x7F;
    if (arg1 == 0) {
        w = D_800D1C00.unk47[D_8009A0A2];
    } else {
        t = D_800D1CA2;
        k = t < 0x20;
        w = t;
        if (k) {
            w = 0x30;
        }
    }
    a = D_800718A8[arg1][0];
    if (arg1 == 0) {
        if (D_8009A0A2 == 1) {
            a++;
        }
    }
    b = D_800718A8[arg1][1];
    lo = v < 8;
    if (arg1 == 0) {
        if (D_8009A0A2 != 0) {
            a--;
        }
        func_800266D4(a, a + 3, b - v, b, lo, w, v);
    } else {
        func_800266D4(a, a + 3, b + (w - v), b + w, lo, w, v);
    }
    if (v != *(s8*)(arg0 + 0x5D)) {
        if (*(s8*)(arg0 + 0x5D) < v) {
            arg0[0x5D] = v;
            return;
        }
        if (*(s8*)(arg0 + 0x5C) & 0x80) {
            arg0[0x5F] = 0x10;
        }
        if (arg1 == 0) {
            func_800266D4(a, a + 3, b - (s8)arg0[0x5D], b - v, 3, 1, 1);
        } else {
            func_800266D4(a, a + 3, b + (w - (s8)arg0[0x5D]), (b - v) + w, 3, 1,
                          1);
        }
        if (*(s8*)(arg0 + 0x5F) != 0) {
            arg0[0x5F]--;
            return;
        }
        if (!(D_8009A420 & 3)) {
            arg0[0x5D]--;
        }
    }
}
