#include "types.h"

extern void func_8002385C(s32, s32, s32);
extern u16 D_800D50DE;
extern u16 D_80093E68;
extern u16 D_8009A42E;

void func_800FAA34_ovl54(u8* arg0) {
    u16 t;

    *(u16*)(arg0 + 6) += 1;
    t = *(u16*)(arg0 + 6);
    if (!(t & 3)) {
        if (D_800D50DE != 0x1F) {
            D_800D50DE++;
            D_8009A42E += 0x20;
            D_80093E68 += 0x400;
        }
    }
    if (D_800D50DE == 0x1F) {
        *(u16*)(arg0 + 4) = 0;
        arg0[1]++;
        func_8002385C(0x7A, 0xFF, 0);
    }
}
