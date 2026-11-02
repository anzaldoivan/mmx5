#include "types.h"

extern u8* func_8002D27C(void);
extern s8 D_800D1C00[];
extern s32 D_800F51F0_ovl20[];
extern u8 D_800F5230_ovl20[];

void func_800F03C4_ovl20(u8* obj) {
    u8* p;
    s32* w;
    s32 k;
    s32 i;
    s32 j;
    s32 mask;
    s8 n;
    s8 last;

    D_800D1C00[0x32] = -1;
    for (i = 0; i < 0x10; i++) {
        if (*(s32*)(obj + 0x84) & D_800F51F0_ovl20[i]) {
            p = func_8002D27C();
            if (p != 0) {
                p[0] = 0x41;
                p[1] = 0x28;
                p[2] = i;
            }
            if (D_800D1C00[0x32] == -1) {
                D_800D1C00[0x32] = i;
            }
        }
    }
    p = func_8002D27C();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x28;
        p[2] = 0x10;
    }
    for (i = 0x11; i < 0x24; i++) {
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x28;
            p[2] = i;
        }
    }
    w = (s32*)(obj + 0x88);
    for (i = 0; i < 6; i++) {
        w[i] &= *(s32*)(obj + 0x84);
    }
    last = 0;
    n = 0;
    k = D_800D1C00[0x2A];
    D_800D1C00[0x30] = D_800F5230_ovl20[k];
    mask = *(s32*)((u8*)w + (k << 2));
    for (j = 0; j < 0x10; j++) {
        if (mask & D_800F51F0_ovl20[j]) {
            last = ++n;
        }
    }
    D_800D1C00[0x31] = last;
    obj[2]++;
}
