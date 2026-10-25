#include "types.h"

extern u8 D_80091C44;
extern X4_BackgroundObj D_8009A1F8[3];

extern void func_8002385C(s32, s32, s32);

void func_800FAE90_ovl49(Ovl45State* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8[0].pad4C[0] = 1;
        D_8009A1F8[0].x_pos.val += 0xFFF4CCCD;
        if (++arg0->unk4 >= 10) {
            D_8009A1F8[0].x_pos.val = 0x2C00000;
            func_8002385C(0x2D, 0xFF, 0);
            arg0->unk4 = 0;
            arg0->unk1++;
        }
    }
}
