#include "types.h"

extern s8 D_800D1C00[];
extern u8 D_800F8BB0_ovl26[];
extern void func_80028B18(s32, s32, s32, void*);
extern void func_800EEE34_ovl26(u8*);

void func_800EED94_ovl26(u8* a0) {
    if (D_800D1C00[0x1D] >= 3) {
        *(s16*)(a0 + 0x1A) = 1;
        a0[5] = 1;
    } else {
        a0[5] = 0;
    }
    if (D_800D1C00[0x1D] == 2) {
        *(s16*)(a0 + 0x1A) = 1;
        func_80028B18(0, 0x3C0, 0x11A0, D_800F8BB0_ovl26);
    }
    a0[6] = 0;
    *(s16*)(a0 + 0x14) = 0;
    *(s16*)(a0 + 0x18) = 0;
    a0[4]++;
    func_800EEE34_ovl26(a0);
}
