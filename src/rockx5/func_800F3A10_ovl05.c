#include "types.h"

extern void func_80028B18(s32, s32, s32, void*);
extern s16 D_800F585C_ovl05[][2];
extern u8 D_800F5868_ovl05[][8];
extern u8 D_8009A244;

void func_800F3A10_ovl05(u8* obj) {
    s8 i = obj[2];

    func_80028B18(0, D_800F585C_ovl05[i][0], D_800F585C_ovl05[i][1],
                  D_800F5868_ovl05[i]);
    D_8009A244 = 1;
    obj[4]++;
}
