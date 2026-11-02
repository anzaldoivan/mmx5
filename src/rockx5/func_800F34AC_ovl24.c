#include "types.h"

extern s32 func_8001D7E8(u8);
extern void func_800F2970_ovl24(void);
extern void func_800F3884_ovl24(u8*);
extern u8 D_800E81D8[];
extern u8 D_8009A427;

static inline s32 func_800F34AC_inl(u8* arg0) {
    u8* obj = D_800E81D8;
    s32 t;
    s32 ret;

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
    return ret;
}

void func_800F34AC_ovl24(u8* arg0) {
    u8* obj = D_800E81D8;

    if (obj[0xA] != 0) {
        obj[0xA]--;
        return;
    }
    if (func_800F34AC_inl(arg0) == 0) {
        func_800F2970_ovl24();
        func_800F3884_ovl24(D_800E81D8);
        if ((s8)arg0[1] != 10) {
            arg0[3] = 12;
            arg0[2]++;
        }
    }
}
