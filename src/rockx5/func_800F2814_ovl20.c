#include "types.h"

extern void func_80017214(u8* a0, s32 a1, s32 a2);
extern void func_8002D89C(u8* obj);
extern s32 D_800D1CAC;

void func_800F2814_ovl20(u8* obj) {
    s32 t;
    s32 q;
    u8 n;

    t = D_800D1CAC;
    if (t < 0) {
        n = 0;
    } else {
        q = t / 216000;
        n = q;
        if (t != q * 216000) {
            n++;
        }
    }
    if (((s8*)obj)[2] == 1) {
        func_80017214(obj, 1, n / 10);
    } else if (((s8*)obj)[2] == 2) {
        if (n >= 20) {
            n -= 20;
        } else if (n >= 10) {
            n -= 10;
        }
        func_80017214(obj, 1, n);
    }
    func_8002D89C(obj);
}
