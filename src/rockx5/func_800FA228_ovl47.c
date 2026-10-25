#include "types.h"

extern u8 D_80091C44;
extern X4_BackgroundObj D_8009A1F8[3];

extern void func_8002385C(s32, s32, s32);

void func_800FA228_ovl47(Ovl45State* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8[1].x_pos.val += 0xA6666;
        if (++arg0->unk4 >= 20) {
            D_8009A1F8[1].x_pos.val = 0x1000000;
            func_8002385C(0x21, 0xFF, 0);
            arg0->unk4 = 0;
            arg0->unk1++;
        }
    }
}
