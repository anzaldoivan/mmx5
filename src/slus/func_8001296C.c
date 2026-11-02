#include "types.h"

extern s32 PadInfoMode(s32, s32, s32);
extern s32 D_8006FB14;
extern s32 D_8006FBF8[];
extern u8* D_8006FC24;
extern u8 D_8006FC28;
extern u8 D_8006FB20[];
extern s8 D_8009A426;
extern u8 D_800D1D10;
extern u8 D_800D5180;

void func_8001296C(s32 arg0) {
    s32 mode;
    u8* p;

    if (D_8009A426 != 0) {
        return;
    }
    if (!(D_800D1D10 & 4)) {
        D_8006FB14 = 0;
        D_8006FC24 = 0;
        D_8006FC28 = 0;
        return;
    }
    if (D_8006FB14 != 0 && D_800D5180 < arg0) {
        return;
    }
    *(volatile s32*)&D_8006FB14 =
        1; // !FAKE: volatile pair keeps the store above the table load
    D_8006FC28 = 0;
    p = (u8*)((volatile s32*)D_8006FBF8)[arg0]; // !FAKE: volatile pair
    D_800D5180 = arg0;
    D_8006FC24 = p;
    mode = PadInfoMode(0, 2, 0);
    if (mode == 4 || mode == 7) {
        u8* q = D_8006FC24;
        D_8006FB20[0] = q[0];
        D_8006FB20[1] = q[1];
    } else {
        D_8006FB20[0] = 0x40;
        D_8006FB20[1] = 1;
    }
}
