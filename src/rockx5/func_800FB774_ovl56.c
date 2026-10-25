#include "types.h"

extern u8 D_80091C44;
extern X4_BackgroundObj D_8009A1F8[3];

s32 func_80016490(s32, s32, void*);

void func_800FB774_ovl56(u8* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8[0].unk3 = 1;
        D_8009A1F8[0].x_pos.i.hi = 0x60;
        D_8009A1F8[0].y_pos.i.hi = 0x300;
        D_8009A1F8[0].pad4C[0] = 1;
        D_8009A1F8[2].unk3 = 0;
        func_80016490(2, 0x5A, 0);
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}
