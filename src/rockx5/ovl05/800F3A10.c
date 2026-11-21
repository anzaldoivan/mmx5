#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"
#include "mmx5/movement.h"

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

#include "shared/func_800F3A80_ovl05.c"
