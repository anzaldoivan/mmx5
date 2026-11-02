#include "types.h"

extern void func_80016490(s32, s32, void*);
extern u16 D_800C9320;
extern s32 D_800EF894_ovl23[];

void func_800EE974_ovl23(s32 arg0) {
    s32 x;

    switch (D_800EF894_ovl23[arg0]) {
    case 0 ... 1:
        x = D_800C9320;
        if (x & 0x1000) {
            D_800EF894_ovl23[arg0]++;
        } else if (x & 0x4000) {
            D_800EF894_ovl23[arg0] = 0;
        }
        break;
    case 2 ... 10:
        if (D_800C9320 & 0x4000) {
            if (++D_800EF894_ovl23[arg0] == 0xB) {
                func_80016490(5, 1, 0);
            }
        }
        break;
    default:
        if (D_800C9320 & 0x5000) {
            D_800EF894_ovl23[arg0] = 0;
        }
        break;
    }
}
