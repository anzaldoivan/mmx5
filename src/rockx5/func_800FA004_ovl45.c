#include "types.h"

extern void func_8002385C(s32, s32, s32);
extern void func_80028B18(s32, s32, s32, void*);
extern u8 D_80091C44;
extern s8 D_8009A298;
extern s16 D_800FA6CC_ovl45[][2];
extern u8 D_800FA6E0_ovl45[][8];

void func_800FA004_ovl45(u8* arg0) {
    u16 t;

    if (D_80091C44 == 0) {
        t = *(u16*)(arg0 + 4);
        if (!(t & 3)) {
            func_80028B18(1, D_800FA6CC_ovl45[(s16)t / 4][0],
                          D_800FA6CC_ovl45[(s16)t / 4][1],
                          D_800FA6E0_ovl45[(s16)t / 4]);
            D_8009A298 = 1;
            if (*(s16*)(arg0 + 4) >= 0x10) {
                func_8002385C(0x18, 0xFF, 0);
                *(u16*)(arg0 + 4) = 0;
                arg0[1]++;
                return;
            }
        }
        *(u16*)(arg0 + 4) += 1;
    }
}
