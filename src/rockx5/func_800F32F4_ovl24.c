#include "types.h"

extern s32 func_8001D7E8(u8);
extern void func_80016490(s32, s32, void*);
extern u8* func_8002D27C(void);
extern u8 D_800E81D8[];
extern u8 D_8009A427;
extern u16 D_800C9320;
extern u8* D_800F5F84_ovl24;

void func_800F32F4_ovl24(u8* arg0) {
    u8* obj = D_800E81D8;
    u8* p;
    s32 t;
    s32 ret;
    s32 one;
    s32 st;

    t = func_8001D7E8(obj[6]);
    if (t != 0) {
        if (t == 1) {
            arg0[1] = 10;
            obj[8] = 1;
            arg0[3] = 1;
        } else {
            arg0[1] = 10;
            st = 2;
            obj[8] = st;
            arg0[3] = 1;
        }
        D_8009A427 = 0;
        ret = 1;
    } else {
        ret = 0;
    }
    if (ret == 0 && (D_800C9320 & 0x40)) {
        func_80016490(0, 0x22, 0);
        st = 7;
        arg0[3] = st;
        one = 1;
        p = func_8002D27C();
        if (p != 0) {
            p[0] = one;
            p[1] = 0x3E;
            p[2] = one;
        }
        D_800F5F84_ovl24 = p;
        *(s16*)(arg0 + 0xA) = one;
        arg0[2]++;
    }
}
