#include "types.h"

extern s32 PadInfoMode(s32, s32, s32);
extern s32 D_8006FB14;
extern u8* D_8006FC24;
extern u8 D_8006FC28;
extern u8 D_8006FB20[];

void func_80012824(void) {
    u8* p;
    s32 mode;

    if (D_8006FB14 != 0) {
        p = D_8006FC24;
        if (p == 0) {
            return;
        }
        if ((u8)++D_8006FC28 < p[2]) {
            return;
        }
        D_8006FC24 = p + 3;
        mode = PadInfoMode(0, 2, 0);
        if (mode == 4 || mode == 7) {
            u8* q = D_8006FC24;
            D_8006FB20[0] = q[0];
            D_8006FB20[1] = q[1];
        } else {
            D_8006FB20[0] = 0x40;
            D_8006FB20[1] = 1;
        }
        D_8006FC28 = 0;
        if (D_8006FC24[2] == 0) {
            D_8006FB14 = 0;
            D_8006FC24 = 0;
        }
    } else {
        mode = PadInfoMode(0, 2, 0);
        if (mode == 4 || mode == 7) {
            D_8006FB20[0] = 0;
            D_8006FB20[1] = 0;
        } else {
            D_8006FB20[0] = 0x40;
            D_8006FB20[1] = 0;
        }
    }
}
