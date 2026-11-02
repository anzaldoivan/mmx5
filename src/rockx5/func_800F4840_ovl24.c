#include "types.h"

void func_800F4DD0_ovl24(u8* obj, s16 x, s16 y, u8 kind, u8 arg4);
extern s32 D_800D1CAC;
extern s16 D_800F5984_ovl24[];

void func_800F4840_ovl24(u8* obj) {
    s32 n;
    s32 q;
    s32 r;
    s32 v = D_800D1CAC;

    if (v <= 0) {
        n = 0;
    } else {
        n = v / 216000;
        if (v != n * 216000) {
            n += 1;
        }
    }
    if (n == 0) {
        func_800F4DD0_ovl24(obj, D_800F5984_ovl24[2], D_800F5984_ovl24[3], 0x80,
                            1);
    } else {
        q = n / 10;
        r = n % 10;
        if (q != 0) {
            func_800F4DD0_ovl24(obj, D_800F5984_ovl24[0], D_800F5984_ovl24[1],
                                q + 0x80, 1);
        }
        func_800F4DD0_ovl24(obj, D_800F5984_ovl24[2], D_800F5984_ovl24[3],
                            r + 0x80, 1);
    }
    obj[5] = 0;
}
