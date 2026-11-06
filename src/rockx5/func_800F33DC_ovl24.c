#include "types.h"

extern s32 func_8001D7E8(u8);
extern s32 func_80016490(s32, s32, void*);
extern u8 D_800E81D8[];
extern u8 D_8009A427;
extern u16 D_800C9320;

void func_800F33DC_ovl24(u8* arg0) {
    u8* obj = D_800E81D8;
    s32 t;
    s32 ret;
    s32 st;

    t = func_8001D7E8(obj[6]);
    if (t != 0) {
        if (t == 1) {
            arg0[1] = 10;
            obj[8] = 1;
            arg0[3] = 1;
        } else {
            arg0[1] = 10;
            obj[8] = 2;
            arg0[3] = 1;
        }
        D_8009A427 = 0;
        ret = 1;
    } else {
        ret = 0;
    }
    if (ret == 0 && (D_800C9320 & 0x40)) {
        func_80016490(0, 0x22, 0);
        arg0[2]++;
        st = 11;
        arg0[3] = st;
        D_800E81D8[0xA] = 3;
    }
}
