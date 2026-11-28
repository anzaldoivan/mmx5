#include "types.h"
#include "mmx5/globals.h"

extern u8 D_80091C44;

void func_800FA230_ovl43(Ovl45State* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8.bg[1].x_pos.val += 0xB3333;
        if (++arg0->unk4 >= 10) {
            D_8009A1F8.bg[1].x_pos.i.hi = 0x130;
            func_8002385C(0xF, 0xFF, 0);
            arg0->unk1++;
        }
    }
}
