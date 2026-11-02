#include "types.h"

extern void SetDispMask(s32);
extern void func_80012EAC(void);
extern void func_800132F8(s32);
extern s32 func_80016490(s32, s32, void*);
extern void func_8001E668(void);
extern void func_8001E6AC(void);
extern void func_800EE974_ovl23(s32);
extern void func_800EEA68_ovl23(s32);
extern u16 D_800C931C[];
extern s32 D_800EF894_ovl23[];

void func_800EEB60_ovl23(u8* arg0) {
    s8 old;
    s32 x;
    s8 m;

    old = *(s8*)(arg0 + 0x44);
    if (D_800C931C[2] & 0x8000) {
        *(s8*)(arg0 + 0x44) = 0;
    }
    if (D_800C931C[2] & 0x2000) {
        *(s8*)(arg0 + 0x44) = 1;
    }
    if (old != *(s8*)(arg0 + 0x44)) {
        func_80016490(5, 0, 0);
        D_800EF894_ovl23[0] = 0;
        D_800EF894_ovl23[1] = 0;
    } else if (old == 0) {
        func_800EE974_ovl23(0);
    } else {
        func_800EEA68_ovl23(old);
    }
    if (*(s8*)(arg0 + 0x44) == 0) {
        arg0[0x4A] = 1;
        arg0[0x49] = 1;
        arg0[0x1BA] = 0;
    } else {
        arg0[0x4A] = 0;
        arg0[0x49] = 5;
        arg0[0x1BA] = 1;
    }
    x = D_800C931C[2];
    if (x & 0x840) {
        arg0[1]++;
        func_800132F8(8);
        func_80016490(5, 1, 0);
        m = *(s8*)(arg0 + 0x44);
        if (D_800EF894_ovl23[m] == 0xB) {
            if (m == 0) {
                arg0[0x4A] = 8;
                arg0[0x49] = 4;
            } else {
                arg0[0x4A] = 0x10;
            }
        }
    } else if (x & 0x10) {
        SetDispMask(0);
        func_8001E668();
        func_8001E6AC();
        func_80012EAC();
    }
}
